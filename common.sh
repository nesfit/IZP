
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
WHITE=$(tput setaf 7)
GRAY=$(tput setaf 8)
BOLD=$(tput bold)
ITALIC=$(tput sitm)
NORMAL=$(tput sgr0)

# print base "[Prefix]" "Message" "pre-prefix" "suffix"
function print_base() {
    printf "$3\r%-18s %-52s$4" "$1" "$2"
}

function print_ok() {
    print_base "${GREEN}[OK]${NORMAL}" "$@"
}

function print_working() {
    [ -n "$DEBUG_ECHO" ] && return 0
    print_base "${GRAY}[LOAD]${NORMAL}" "$@"
}

function print_fail() {
    print_base "${RED}[FAIL]${NORMAL}" "$@"
}

function print_debug() {
    [ -z "$DEBUG_ECHO" ] && return 0
    >&2 print_base "${YELLOW}[DBG]${NORMAL}" "$1" "" "\n"
}

function print_stderr_warn() {
    PRE="$2"
    [ -z "$DEBUG_ECHO" ] && PRE="\n"
    >&2 print_base "${RED}[WARN]${NORMAL}" "$1" "$PRE" "\n"
}
