#!/usr/bin/env bash

[ -n "$DEBUG_BASH" ] && set -x

SCRIPT_DIRPATH="$(realpath $(dirname $0))"
TESTS_DIRPATH="$SCRIPT_DIRPATH/../reference"
OUTS_DIRPATH="$SCRIPT_DIRPATH/../student"
SOLUTION_DIRPATH="$(realpath $(dirname $SCRIPT_DIRPATH)/..)"

RESULTS_FILEPATH="$SCRIPT_DIRPATH/../results.csv"
MAKEFILE="$SOLUTION_DIRPATH/Makefile"

[ -z "$MAKE_RECIPE_NAME" ] && MAKE_RECIPE_NAME="main-test"
[ -z "$RUN_TIMEOUT" ] && RUN_TIMEOUT="1s"
[ -z "$RUN_NEXT_BEHAVIOUR" ] && RUN_NEXT_BEHAVIOUR="ask"
RUN_FILENAME="$MAKE_RECIPE_NAME"

. "$SCRIPT_DIRPATH/common.sh"

# validate config when not in debug mode
if [ -z "$DEBUG" ]; then
    . "$SOLUTION_DIRPATH/student-config.sh"

    if [ -z "$PROJECT_AUTHOR" ]; then
        if [[ -z "$LOGIN" ]]; then
            >&2 echo -e "${RED}No faculty login has been set!${NORMAL}\n${GRAY}Configure it in${NORMAL} /student-config.sh"
            exit 1
        elif [[ "$LOGIN" =~ ^(x[a-z]{5}[a-z0-9]{2})$ && "$LOGIN" != "xlogin00" ]]; then
            # FIT LOGIN
            :
        elif [[ "$LOGIN" =~ ^([0-9]{6})$ ]]; then
            # VUT ID
            :
        else
            >&2 echo -e "${RED}Invalid student identifier ${NORMAL}${LOGIN}${RED}!"
            >&2 echo -e "${GRAY}Expected format is either ${NORMAL}xlogin00${GRAY} or ${NORMAL}VUTID${GRAY}.${NORMAL}"
            exit 2
        fi
    fi
fi

# load definitions from configuration
if [ -f "$SCRIPT_DIRPATH/../config.sh" ]; then
    . "$SCRIPT_DIRPATH/../config.sh"
fi

RUN_FILEPATH="$SOLUTION_DIRPATH/$RUN_FILENAME"

function check_output() {
    OUT_TYPE="$1"       # output type: out, err
    OUT_DIRPATH="$2"    # real outptu directory for a test
    REF_DIRPATH="$3"    # reference output directory for a test

    print_debug "check_output($1, $2, $3) "

    OUT_FILEPATH="$OUT_DIRPATH/$OUT_TYPE"
    REF_EXACT_FILEPATH="$REF_DIRPATH/$OUT_TYPE.exact"
    REF_MATCH_FILEPATH="$REF_DIRPATH/$OUT_TYPE.match"
    REF_MATCH_INV_FILEPATH="$REF_DIRPATH/$OUT_TYPE.no-match"
    REF_REGEX_FILEPATH="$REF_DIRPATH/$OUT_TYPE.regex"
    REF_REGEX_INV_FILEPATH="$REF_DIRPATH/$OUT_TYPE.regex-inv"

    if [ -f "$REF_EXACT_FILEPATH" ]; then
        # exact match with diff
        DIFF="$(diff --new-file --unified=6 --label="Reference output    (lines missing from your output)" "$REF_EXACT_FILEPATH" --label="Your program output (extra lines not in reference)" "$OUT_FILEPATH")"
        DIFF_RC=$?

        print_debug "  diff \$?=$DIFF_RC"
        printf "\n\tstd$OUT_TYPE ${GRAY}differs: it was expected ${NORMAL}to be the same${GRAY} as reference:${NORMAL}\n%s" "$DIFF"
        return $DIFF_RC
    fi

    function process_diff_details() {
        RESULT_ACTUAL="$1"
        RESULT_EXPECTED_MATCH="$2"
        RESULT_EXPECTED="$3"
        DESCRIPTION="$4"
        DETAILS_FILEPATH="$5"

        print_debug "  RESULT_ACTUAL=$RESULT_ACTUAL"
        print_debug "  RESULT_EXPECTED=$RESULT_EXPECTED"

        function print_diff_details() {
            [ -n "$ECHO_QUIET" ] && return

            printf "\n\tstd$OUT_TYPE:\n"
            cat "$OUT_FILEPATH"

            printf "\n\tstd$OUT_TYPE ${GRAY}differs: $DESCRIPTION ${NORMAL}\n"
            if [ -f "$DETAILS_FILEPATH" ]; then
                cat "$REF_MATCH_FILEPATH"
            fi
        }

        if [ -z "$MATCHED_COUNT" ]; then
            print_stderr_warn "  diff error: match expected, but reference is probably empty!"
            return 1

        elif [ "$RESULT_EXPECTED_MATCH" = "eq" ] && [ "$MATCHED_COUNT" -eq "$RESULT_EXPECTED" ]; then
            print_diff_details
            return 1

        elif [ "$RESULT_EXPECTED_MATCH" = "ne" ] && [ "$MATCHED_COUNT" -ne "$RESULT_EXPECTED" ]; then
            print_diff_details
            return 1

        fi

        return 0
    }

    STATUS=0
    if [ -f "$REF_MATCH_FILEPATH" ]; then
        # soft match with grep
        CMD="grep --fixed-strings --count --text --file "$REF_MATCH_FILEPATH" "$OUT_FILEPATH""
        print_debug "  $CMD"

        MATCHED_COUNT="$($CMD)"
        process_diff_details $MATCHED_COUNT eq 0 "it was expected ${NORMAL}to find an occurrence ${GRAY}of:" "$REF_MATCH_FILEPATH"
        return $?
    fi

    if [ -f "$REF_MATCH_INV_FILEPATH" ]; then
        # soft match with grep
        CMD="grep --fixed-strings --count --text --file "$REF_MATCH_INV_FILEPATH" "$OUT_FILEPATH""
        print_debug "  $CMD"

        MATCHED_COUNT="$($CMD)"
        process_diff_details $MATCHED_COUNT ne 0 "it was expected ${RED}not ${NORMAL}to find an occurrence ${GRAY}of:" "$REF_MATCH_INV_FILEPATH"
        return $?
    fi

    if [ -f "$REF_REGEX_FILEPATH" ]; then
        # regex match with grep
        CMD="grep --extended-regexp --count --text --file "$REF_REGEX_FILEPATH" "$OUT_FILEPATH""
        print_debug "  $CMD"

        MATCHED_COUNT="$($CMD)"
        process_diff_details $MATCHED_COUNT eq 0 "it was expected ${NORMAL}to match ${GRAY}with:" "$REF_REGEX_FILEPATH"
        return $?
    fi

    if [ -f "$REF_REGEX_INV_FILEPATH" ]; then
        # inverted regex match with grep
        CMD="grep --extended-regexp --count --text --file "$REF_REGEX_INV_FILEPATH" "$OUT_FILEPATH""
        print_debug "  $CMD"

        MATCHED_COUNT="$($CMD)"
        process_diff_details $MATCHED_COUNT ne 0 "it was expected ${RED}not ${NORMAL}to match ${GRAY}with:" "$REF_REGEX_INV_FILEPATH"
        return $?
    fi

    print_debug "  no conditions defined for std$OUT_TYPE, match success"
    return 0
}

function check_stdout() {
    check_output "out" "$1" "$2"
}

function check_stderr() {
    check_output "err" "$1" "$2"
}

function run_test_with_args() {
    OUT_DIRPATH="$1"
    REF_DIRPATH="$2"
    ARGS="$3"

    # output files
    RUN_OUT_FILEPATH="$OUT_DIRPATH/out"
    RUN_OUT_ERR_FILEPATH="$OUT_DIRPATH/err"
    RUN_RETURN_CODE_FILEPATH="$OUT_DIRPATH/rc"

    # input files
    ENV_FILEPATH="$REF_DIRPATH/env.sh"
    ARGS_FILEPATH="$REF_DIRPATH/args"
    INPUT_FILEPATH="$REF_DIRPATH/in"
    RETURN_CODE_FILEPATH="$REF_DIRPATH/rc"

    EXPECTED_RETURN_CODE=0
    [ -f "$RETURN_CODE_FILEPATH" ] && EXPECTED_RETURN_CODE="$(cat "$RETURN_CODE_FILEPATH")"

    # load default config
    [ -f "$TESTS_DIRPATH/env.sh" ] && . "$TESTS_DIRPATH/env.sh"

    # load config from environment
    [ -f "$ENV_FILEPATH" ] && . "$ENV_FILEPATH"

    function print_fail_head_once() {
        [ "$__ERR_HEAD_PRINTED" -ne "0" ] && return 0
        __ERR_HEAD_PRINTED=1

        # test header
        if [ -z "$ECHO_QUIET" ]; then
            print_fail "Test $TEST_ID" "" "\n"
        else
            print_fail "Test $TEST_ID"
            return
        fi

        # additional test description
        if [ -f "$DESC_FILEPATH" ]; then
            printf "\t${ITALIC}"
            cat "$DESC_FILEPATH"
            printf "${NORMAL}"
        fi

        # executable invocation, cli args
        __SEP=""
        [ -n "$ARGS" ] && __SEP=" "
        printf "\t${GRAY}run '${NORMAL}$(basename $RUN_FILEPATH)$__SEP$ARGS${GRAY}' "
        # test stdin
        if [ -f "$INPUT_FILEPATH" ]; then
            printf "with ${NORMAL}stdin${GRAY}:${NORMAL}\n"
            cat $INPUT_FILEPATH
        else
            printf "with no input${NORMAL}"
        fi
    }

    # define the array
    print_debug "running $RUN_FILEPATH $ARGS"
    print_debug "  TEST_NAME=$TEST_NAME"

    # export relevant test variables by default
    export TEST_NAME

    VALGRIND_CALL=""
    if [[ -n "$VALGRIND" && "$VALGRIND" -eq 1 ]]; then
        [[ -z "$VALGRIND_FLAGS" ]] && VALGRIND_FLAGS="--leak-check=summary --show-reachable=yes"
		VALGRIND_CALL="valgrind $VALGRIND_FLAGS"

    fi

    if [ -f "$INPUT_FILEPATH" ]; then
        # run with input
        timeout --preserve-status "$RUN_TIMEOUT" $VALGRIND_CALL "$RUN_FILEPATH" $ARGS <"$INPUT_FILEPATH" >"$RUN_OUT_FILEPATH" 2>"$RUN_OUT_ERR_FILEPATH"
        TEST_RC="$?"

    else
        # run without input
        timeout --preserve-status "$RUN_TIMEOUT" $VALGRIND_CALL "$RUN_FILEPATH" $ARGS >"$RUN_OUT_FILEPATH" 2>"$RUN_OUT_ERR_FILEPATH"
        TEST_RC="$?"

    fi

    if [[ -n "$VALGRIND" && "$VALGRIND" -eq 1 ]]; then
        content="$(cat "$RUN_OUT_ERR_FILEPATH")"
        echo "$content" | sed -nr 's/^([0-9=]* )?(.*)$/\2/p' | grep --invert-match -E "^(Command|Copyright|Using Valgrind)" >"$RUN_OUT_ERR_FILEPATH"
        VALGRIND=0
        VALGRIND_FLAGS=""

    fi

    # print outputs
    print_working "Test $TEST_ID: validating"
    print_debug "terminated with $TEST_RC"
    print_debug "out:"
    [ -n "$DEBUG_ECHO" ] && cat "$RUN_OUT_FILEPATH"
    print_debug "err:"
    [ -n "$DEBUG_ECHO" ] && cat "$RUN_OUT_ERR_FILEPATH"

    # test return code
    TEST_RC_DIFF="0"
    [ -z "$EXPECTED_RETURN_CODE" ] && EXPECTED_RETURN_CODE="0"
    if [ "$TEST_RC" -ne "$EXPECTED_RETURN_CODE" ]; then
        TEST_RC_DIFF="1"
    fi

    # test stdout
    TEST_OUT="$(check_stdout "$OUT_DIRPATH" "$REF_DIRPATH")"
    TEST_OUT_DIFF=$?
    
    # test stderr
    TEST_OUT_ERR="$(check_stderr "$OUT_DIRPATH" "$REF_DIRPATH")"
    TEST_OUT_ERR_DIFF=$?

    print_debug "TEST_RC_DIFF=$TEST_RC_DIFF, TEST_OUT_DIFF=$TEST_OUT_DIFF, TEST_OUT_ERR_DIFF=$TEST_OUT_ERR_DIFF"
    print_debug "TEST_OUT=$TEST_OUT"
    print_debug "TEST_OUT_ERR=$TEST_OUT_ERR"

    # inform about return code test results
    if [ "$TEST_RC_DIFF" -ne "0" ]; then
        print_fail_head_once
        if [ -z "$ECHO_QUIET" ]; then
            printf "\n\treturn code ${GRAY}differs: expected ${NORMAL}%s${GRAY} ${NORMAL}but got ${RED}%s${NORMAL}" "$EXPECTED_RETURN_CODE" "$TEST_RC"

            if [ "$TEST_RC" -eq "139" ]; then
                printf "\n\t\t${GRAY}signal meaning:${RED} Segmentation Fault${NORMAL}\n"
            elif [ "$TEST_RC" -eq "134" ]; then
                printf "\n\t\t${GRAY}signal meaning:${RED} Aborted${NORMAL}\n"
            elif [ "$TEST_RC" -eq "99" ]; then
                printf "\n\t\t${GRAY}possible misconfiguration:${RED} test ${NORMAL}${TEST_NAME}${RED} not found${NORMAL}\n"
            fi
        fi
    fi

    # inform about stdout test results
    if [ "$TEST_RC" -ne "99" ] && [ "$TEST_OUT_DIFF" -ne "0" ]; then
        print_fail_head_once
        [ -z "$ECHO_QUIET" ] && printf "$TEST_OUT\n"
    fi

    # inform about stderr test results
    if [ "$TEST_RC" -ne "99" ] && [ "$TEST_OUT_ERR_DIFF" -ne "0" ]; then
        print_fail_head_once
        [ -z "$ECHO_QUIET" ] && printf "$TEST_OUT_ERR\n"
    fi

    # finalize test
    if [ "$TEST_RC_DIFF" -eq "0" ] && [ "$TEST_OUT_DIFF" -eq "0" ] && [ "$TEST_OUT_ERR_DIFF" -eq "0" ]; then
        return 0
    else
        return 1
    fi
}

rm -Rf "$OUTS_DIRPATH"

printf "test_id,test_desc,return_code,stdout_diff,stderr_diff\n" >"$RESULTS_FILEPATH"

print_working "Compiling project solution" "" "\n"
print_debug "making $MAKE_RECIPE_NAME using $MAKEFILE"

# clean and compile the sources
make clean
make -f "$MAKEFILE" $MAKE_RECIPE_NAME
if [ $? -ne 0 ]; then
    print_fail "Failed compiling the project solution"
    exit 0
fi;

((successful=0))
((failed=0))

# run all test cases
for TEST_DIRPATH in $TESTS_DIRPATH/[0-9]*; do
    if [ ! -d "$TEST_DIRPATH" ]; then
        print_stderr_warn "No tests were found in $TESTS_DIRPATH!"
        exit 1
    fi

    TEST_ID="$(basename $TEST_DIRPATH)"
    OUT_DIRPATH="$OUTS_DIRPATH/$TEST_ID"
    REF_DIRPATH="$TESTS_DIRPATH/$TEST_ID"

    print_debug "starting test $TEST_ID at $OUT_DIRPATH"
    print_working "Test $TEST_ID: preparing"
    mkdir -p "$OUT_DIRPATH"

    # input files
    ARGS_FILEPATH="$REF_DIRPATH/args"
    DESC_FILEPATH="$REF_DIRPATH/desc"

    print_working "Test $TEST_ID: running"
    if [ -f "$ARGS_FILEPATH" ]; then
        # args are defined
        while read ARGSET; do
            __ERR_HEAD_PRINTED=0
            run_test_with_args "$OUT_DIRPATH" "$REF_DIRPATH" "$ARGSET"
            [ $? -ne 0 ] && break
        done <"$ARGS_FILEPATH"
    else
        # args are not defined
        __ERR_HEAD_PRINTED=0
        run_test_with_args "$OUT_DIRPATH" "$REF_DIRPATH"
    fi

    if [ "$__ERR_HEAD_PRINTED" -eq 0 ]; then
        print_ok "Test $TEST_ID"
        ((successful++))
    else
        ((failed++))

        if [ "$RUN_NEXT_BEHAVIOUR" == "ask" ]; then
            while :
            do
                echo ""
                read -n1 -p "${GRAY}The previous failed, continue? [${NORMAL}a=all${GRAY},${NORMAL}n=next${GRAY},${NORMAL}q=quit${GRAY}]: ${NORMAL}" ANS
                case "$ANS" in
                    a)
                    RUN_NEXT_BEHAVIOUR=""
                    break;
                    ;;

                    n)
                    RUN_NEXT_BEHAVIOUR="ask"
                    break;
                    ;;

                    q)
                    break 2;
                    ;;

                    *)
                    continue;
                    ;;
                esac
            done
        fi
    fi

    DESC=""
    [ -f "$DESC_FILEPATH" ] && DESC="$(cat "$DESC_FILEPATH")"
    printf "%s,%s,%d,%d,%d\n" "$TEST_ID" "$DESC" "$TEST_RC_DIFF" "$TEST_OUT_DIFF" "$TEST_OUT_ERR_DIFF" >>"$RESULTS_FILEPATH"
    echo ""

done

. "$SCRIPT_DIRPATH/api.sh"

if [ "$PROJECT_SUBMIT_MODE" = "tests" ]; then
    api_submit_report "$RESULTS_FILEPATH"
elif [ "$PROJECT_SUBMIT_MODE" = "sources" ]; then
    api_submit_report_with_sources "$RESULTS_FILEPATH"
fi

((total=successful+failed))
pct=$(awk -v successful=$successful -v total=$total 'BEGIN { print  ( successful / total * 100 ) }')
FINAL_TOUCH=""
if [ $(printf "%.0f" $pct) -gt 99 ]; then
    COLOR="${GREEN}${BOLD}"
    FINAL_TOUCH=" 🎉"
elif [ $(printf "%.0f" $pct) -ge 66 ]; then
    COLOR="${YELLOW}${BOLD}"
else
    COLOR="${RED}${BOLD}"
fi

echo ""
printf "\r${GRAY}Test summary:${NORMAL} passed ${COLOR}%2d${NORMAL}${GRAY}/${NORMAL}%2d ${COLOR}%5.1f%%${NORMAL}$FINAL_TOUCH\n" $successful $total $pct
