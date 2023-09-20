# Replit Template

**Branch switching**
```
git switch "branch_name"
git submodule update --init
```

**Submodule updates**
```
git submodule update --init --remote
git checkout main -- README.md student-config.sh .tests/.gitignore .tests/config.sh .tests/README.md -p
```

## Creating new branches
```
BRANCH="branch_name"
git branch -c main "$BRANCH"
git submodule set-branch --branch "$BRANCH" solution
```

## Propagating changes from master
```
git fetch
for BRANCH in $(git branch -r | grep -E -o "\d{2}-\d{2}-.*");
do
    echo "\nRebase $BRANCH"
    read
    git checkout $BRANCH || break
    git pull || break
    git reset --hard origin/"$BRANCH" || break
    git rebase master || break
    git push --force || break
done
```

## Propagating changes of scripts
```
git fetch
for BRANCH in $(git branch -r | grep -E -o "\d{2}-\d{2}-.*");
do
    echo "\nSync test scripts on $BRANCH"
    read
    git checkout $BRANCH || break
    git pull || break
    git submodule update --remote .tests/scripts || break
    git add .tests/scripts || break
    git commit -m "feat: sync latest test scripts" || break
    git push || break
done
```
