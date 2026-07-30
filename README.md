# kshell — A Simple UNIX Shell in C

> A custom shell built from scratch to explore UNIX system calls, process management, and the internals of how shells work.

---

## Table of Contents

- [Motivation](#motivation)
- [Features](#features)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Requirements](#requirements)
- [Building the Project](#building-the-project)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [Rules and Guidelines](#rules-and-guidelines)
- [Learning Resources](#learning-resources)

---

## Motivation

Most developers use a shell every day without thinking about what happens under the hood. This project exists to answer that question by building one from scratch.

`kshell` is a minimal UNIX shell written in C, built primarily to understand:

- How a shell reads and parses user input
- How processes are created and managed using `fork()` and `execve()`
- How parent and child processes communicate via exit codes
- The relationship between a shell and the OS kernel

---

## Features

**Currently implemented:**
- Interactive prompt loop (`kobby/ksh -->`)
- `fork()` demonstration — correctly distinguishes parent and child processes

**Planned (see [Roadmap](#roadmap)):**
- Read input from `stdin` using `getline` or `fgets`
- Tokenize/split commands into arguments
- Execute commands via `execve(2)`
- Handle built-in commands (`exit`, `cd`, `env`)
- Proper error handling and exit codes

---

## Project Structure

```
kshell/
├── main.c          # Main shell loop — entry point (WIP)
├── get_fork.c      # Demonstration of fork() and process creation
├── loop.c          # Early prototype of the input loop
├── rot13.py        # ROT-13 utility (Python helper/experiment)
├── oshell.sh       # Build script — compiles main.c to main.x
├── .gitignore      # Excludes compiled binaries and OS artifacts
└── README.md       # This file
```

---

## How It Works

A shell at its core does four things in a loop:

```
1. Print a prompt
2. Read a line of input from the user
3. Parse the input into a command + arguments
4. Fork a child process and exec the command
```

Here is what that looks like in `main.c` (work in progress):

```c
while (flag == 1) {
    printf("kobby/ksh --> ");
    // 1. Read input from stdin
    // 2. Split/tokenize the input
    // 3. fork() to create a child process
    // 4. execve() the command in the child
    // 5. Parent waits for child to finish
}
```

### fork() Explained

When `fork()` is called, the OS creates an exact copy of the current process. The key detail is the return value:

| Return Value | Meaning |
|---|---|
| `< 0` | Fork failed (error) |
| `== 0` | You are in the **child** process |
| `> 0` | You are in the **parent** process (value is child's PID) |

See `get_fork.c` for a working demonstration.

---

## Requirements

- GCC (GNU Compiler Collection)
- A UNIX-based OS (Linux or macOS)
- `bash` (to run the build script)

Check your GCC version:
```bash
gcc --version
```

---

## Building the Project

You can compile manually:

```bash
gcc main.c -o main.x
```

Or use the provided build script:

```bash
bash kshell.sh
```

> **Note:** Compiled binaries (`.x` files) are excluded from version control via `.gitignore`.

To compile and run in one step:
```bash
gcc main.c -o main.x && ./main.x
```

---

## Usage

Once built, launch the shell:

```bash
./main.x
```

You will see the custom prompt:

```
kobby/ksh -->
```

From here, type commands as you would in any shell. Exit with `Ctrl+C` (until a proper `exit` built-in is implemented).

---

## Roadmap

- [x] Read a full line of input from `stdin`
- [ ] Tokenize input into command + argument array (`strtok`)
- [ ] Execute commands with `execve(2)`
- [ ] Wait for child process to finish with `waitpid()`
- [ ] Handle built-in commands: `exit`, `cd`, `env`
- [ ] Gracefully handle `Ctrl+C` (SIGINT) and `Ctrl+D` (EOF)
- [ ] Support for environment variables
- [ ] Pipe (`|`) support
- [ ] Input/output redirection (`>`, `<`, `>>`)

---

## Rules and Guidelines

- Compiled executables use the `.x` extension for consistency (e.g. `main.x`)
- Executables are **not** committed to the repo — they are excluded by `.gitignore`
- All C code targets C99 or later (`gcc -std=c99`)
- Keep experimental/demo files (like `loop.c`, `get_fork.c`) separate from the main shell logic

---

## Learning Resources

These references are useful when building a shell from scratch:

- [`fork(2)` — Linux man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [`execve(2)` — Linux man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [`waitpid(2)` — Linux man page](https://man7.org/linux/man-pages/man2/waitpid.2.html)
- [Write a Shell in C — Stephen Brennan's Tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [The Linux Programming Interface — Michael Kerrisk](https://man7.org/tlpi/)
