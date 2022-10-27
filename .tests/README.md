# Testing

Tests are run by running the `run_tests.sh` script.
There are special environment variables accepted:
  - `DEBUG`: skips login validation and result submission
  - `DEBUG_ECHO`: enables script debugging

## Updating

```
git restore --source main .tests
git restore --source main .gitignore
git restore --source main Makefile
git restore --source main student-config.sh
git checkout .tests/reference
```

## Test cases

Test cases are under the `tests` directory.
Each test case is in its own directory.
The directory name must begin with a number and may be followed by sluggified name.
The tests are defined by numerous files as described below:

### Test definition

These files define how the program is run.

| File name | Description |
| --------- | ----------- |
| `args`    | Defines the CLI arguments passed to the program
| `in`      | Defines the content of `stdin` passed to the program
| `desc`    | Provides description of the test

All the files are optional.
This is the default behaviour when missing:

| File name | Default behaviour when missing |
| --------- | ------------------------------ |
| `args`    | No arguments passed to the program
| `in`      | No content passed on `stdin` of the program
| `desc`    | Empty test description

### Result definition

These files define conditions of the successful test.

| File name   | Description |
| ----------- | ----------- |
| `rc`        | Expected return (exit) code of the program
| `out.$MODE` | Expected content of `stdout` matched by a specific `$MODE`.
| `err.$MODE` | Expected content of `stderr` matched by a specific `$MODE`.

All the files are optional.
This is the default behaviour when missing:

| File name | Default behaviour when missing |
| --------- | ------------------------------ |
| `rc`      | Program must exit with code `0`
| `out`     | Program can output anything to `stdout`
| `err`     | Program can output anything to `stderr`

**Match modes**

These are the supported modes for the `$MODE` variable.
These define how the output condition is to be interpreted.

| Mode        | Description |
| ----------- | ----------- |
| `exact`     | The outputs **must** match the reference exactly.
| `match`     | The outputs **must** contain the reference somewhere.
| `no-match`  | The outputs **must not** contain the reference anywhere.
| `regex`     | The outputs **must** match the reference regex somewhere.
| `regex-inv` | The outputs **must not** match the reference regex anywhere.
