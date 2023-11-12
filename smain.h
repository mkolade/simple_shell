#ifndef _SMAIN_H_
#define _SMAIN_H_

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>


#define TOKEN_DELIM " \t\r\n\a"
#define TOKEN_SIZE 128
#define BUFSIZE 1024

/* This Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - A struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by user
 * @args: arguments from command line
 * @status: holds the last status of the shell
 * @counter: line counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_data;
#endif /* smain.h */
