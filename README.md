# 0x16. C - Simple Shell

## Introduction
This repository will contain the source code for a simple shell program written in C. This shell is a command-line interpreter that allows users to interact with the operating system by executing commands and managing processes swiftly.

## Table of Contents
- [Who designed and implemented the original Unix operating system](#who-designed-and-implemented-the-original-unix-operating-system)
- [Who wrote the first version of the UNIX shell](#who-wrote-the-first-version-of-the-unix-shell)
- [Who invented the B programming language](#who-invented-the-b-programming-language)
- [Who is Ken Thompson](#who-is-ken-thompson)
- [How does a shell work](#how-does-a-shell-work)
- [What is a pid and a ppid](#what-is-a-pid-and-a-ppid)
- [How to manipulate the environment of the current process](#how-to-manipulate-the-environment-of-the-current-process)
- [What is the difference between a function and a system call](#what-is-the-difference-between-a-function-and-a-system-call)
- [How to create processes](#how-to-create-processes)
- [What are the three prototypes of `main`](#what-are-the-three-prototypes-of-main)
- [How does the shell use the `PATH` to find the programs](#how-does-the-shell-use-the-path-to-find-the-programs)
- [How to execute another program with the `execve` system call](#how-to-execute-another-program-with-the-execve-system-call)
- [How to suspend the execution of a process until one of its children terminates](#how-to-suspend-the-execution-of-a-process-until-one-of-its-children-terminates)
- [What is `EOF` / "end-of-file"](#what-is-eof--end-of-file)
