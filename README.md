# Replit Template

**Branch switching**
```
git switch "branch_name"
git submodule update --init
```

**Submodule updates**
```
git submodule update --init --remote --rebase
git checkout main -- README.md student-config.sh .tests/.gitignore .tests/config.sh .tests/README.md -p
```

## Creating new branches
```
BRANCH="branch_name"
git branch -c main "$BRANCH"
git submodule set-branch --branch "$BRANCH" solution
```
