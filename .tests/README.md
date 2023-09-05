# Testing

Tests are run by running the `scripts/run_tests.sh` script.
Further defails about testing can be found in `scripts/README.md`.

## Updating

### Getting latest changes
```
git checkout main -- .tests/.gitignore .tests/README.md .tests/config.sh -p
git checkout .tests/reference
```

### Publishing new changes
```
git push origin HEAD:_test-scripts
```
