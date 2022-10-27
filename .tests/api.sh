
RESULT_API_URL="$RESULT_API_URL_BASE/v1/task"

function api_submit_report() {
    RESULT_CSV_FILEPATH="$1"
    ADDITIONAL_ARGS="$2"

    print_working "Submitting test results"

    [ -n "$DEBUG" ] && ADDITIONAL_ARGS="$ADDITIONAL_ARGS --verbose"
    [ -z "$DEBUG" ] && ADDITIONAL_ARGS="$ADDITIONAL_ARGS --silent"
    print_debug "RESULT_CSV_FILEPATH=$RESULT_CSV_FILEPATH"
    print_debug "ADDITIONAL_ARGS=$ADDITIONAL_ARGS"

    OUTPUT_FILEPATH="$(mktemp)"
    HTTP_CODE="$(curl \
        --output "$OUTPUT_FILEPATH" \
        --write-out "%{http_code}" \
        --connect-timeout 2 \
        -H "accept: application/json" \
        -H "connection: close" \
        -F group_id="$PROJECT_GROUP_ID" \
        -F task_id="$PROJECT_TASK_ID" \
        -F login="$PROJECT_AUTHOR" \
        -F results="@$RESULT_CSV_FILEPATH;type=text/csv" \
        $ADDITIONAL_ARGS \
        "$RESULT_API_URL/report")"
    
    if [ ${HTTP_CODE} -lt 200 ] || [ ${HTTP_CODE} -gt 299 ]; then
        print_stderr_warn "Result reporting failed with code $HTTP_CODE!" "" "\n"
        print_debug "Server response: '$(cat $OUTPUT_FILEPATH)'"
        return 1
    fi
    
    return 0
}

function api_submit_report_with_sources() {
    RESULT_CSV_FILEPATH="$1"

    print_working "Collecting sources to submit"

    sources=()
    for RELATIVE_FILEPATH in $PROJECT_SUBMIT_SOURCES; do
        FILEPATH="$SOLUTION_DIRPATH/$RELATIVE_FILEPATH"
        if [ ! -f "$FILEPATH" ]; then
            print_stderr_warn "file '$FILEPATH' to be submitted does not exist"
            continue
        fi

        sources+=("-F sources=@$FILEPATH;type=text/plain")
    done

    api_submit_report "$RESULT_CSV_FILEPATH" "${sources[@]}"
    RESULT=$?

    if [ $RESULT -eq 0 ]; then
        print_ok "Sources and results submitted successfully!" "" "\n"
    fi
    
    return $RESULT
}
