# Testing

Tests are run by running the `run_tests.sh` script.
There are special environment variables accepted:
  - `DEBUG`: skips login validation and result submission when defined
  - `DEBUG_ECHO`: enables script debugging when defined
  - `DEBUG_BASH`: enables advanced script debugging when defined
  - `ECHO_QUIET`: hides test case details (errpr details, diffs) when defined

# Test cases

Test cases are under the `tests` directory.
Each test case is in its own directory.
The directory name must begin with a number and may be followed by sluggified name (e.g. `test-some_name`).
The tests are defined by numerous files as described below:

### Test definition

These files define how the program is run.

| File name | Description                                                  | Defaults when missing                       |
|-----------|--------------------------------------------------------------|---------------------------------------------|
| `args`    | Each row defines one program invocation with given arguments | Program is invoked once, no arguments       |      
| `in`      | Defines the content of `stdin` always passed to the program  | No content passed on `stdin` of the program | 
| `desc`    | Provides description of the given test                       | Empty test description                      |

All the files are optional.

### Result definition

These files define conditions of the successful test.

| File name   | Description                                                | Defaults when missing                   |
|-------------|------------------------------------------------------------|-----------------------------------------|
| `rc`        | Expected return (exit) code of the program                 | Program must exit with code `0`         |
| `out.$MODE` | Expected content of `stdout` matched by a specific `$MODE` | Program can output anything to `stdout` |
| `err.$MODE` | Expected content of `stderr` matched by a specific `$MODE` | Program can output anything to `stderr` |

All the files are optional.

**Match modes**

These are the supported modes for the `$MODE` variable.
These define how the output condition is to be interpreted.

| Mode        | Description                                                  |
|-------------|--------------------------------------------------------------|
| `exact`     | The content **must** match the reference exactly.            |
| `match`     | The content **must** contain the reference somewhere.        |
| `no-match`  | The content **must not** contain the reference anywhere.     |
| `regex`     | The content **must** match the reference regex somewhere.    |
| `regex-inv` | The content **must not** match the reference regex anywhere. |
