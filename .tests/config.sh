
PROJECT_SUBMIT_SOURCES=("main.c")

# REPLIT.COM configuration
PROJECT_GROUP_ID="$REPL_OWNER"
PROJECT_TASK_ID="$REPL_SLUG"
PROJECT_AUTHOR="$LOGIN"

if [[ -z "$PROJECT_TASK_ID" && -n "$IZP_BRANCH" ]]; then
    # try getting task ID from JupyterHub environment
    PROJECT_TASK_ID="${IZP_BRANCH:0:5}"

    if [[ -z "$PROJECT_GROUP_ID" ]]; then
        PROJECT_GROUP_ID="#detect"
    fi
fi

if [[ -z "$PROJECT_AUTHOR" && "$JUPYTERHUB_USER" ==  *"@vutbr.cz" ]] \
|| [[ -z "$PROJECT_AUTHOR" && "$JUPYTERHUB_USER" ==  *"@vut.cz" ]]; then
    # try getting login from JupyterHub environment
    PROJECT_AUTHOR="${JUPYTERHUB_USER%%@*}"
fi

# variable defaults
[ -z "$PROJECT_SUBMIT_MODE" ] && [ -n "$PROJECT_TASK_ID" ] && PROJECT_SUBMIT_MODE="tests"
[ -z "$PROJECT_GROUP_ID" ] && PROJECT_GROUP_ID="github.com-nesad-IZP"
[ -z "$PROJECT_TASK_ID" ] && PROJECT_TASK_ID="local-dev"
[ -z "$PROJECT_AUTHOR" ] && PROJECT_AUTHOR="$USER"

RESULT_API_URL_BASE="https://teaching.api.bazar.nesad.fit.vutbr.cz"
