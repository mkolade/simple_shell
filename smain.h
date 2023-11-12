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

/**
 * struct div - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: singly linked list to store separators
 */
typedef struct div
{
	char separator;
	struct div *next;
} div_list;

/**
 * struct cmd_line_list - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct cmd_line_list
{
	char *line;
	struct cmd_line_list *next;
} line_list;

/**
 * struct store_var_list - single linked list
 * @len_var: length of variable
 * @val: value of variable
 * @len_val: length of value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct store_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct store_var_list *next;
} store_var;

/**
 * struct built_in_s - Builtin struct for command args.
 * @name: name of command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct built_in_s
{
	char *name;
	int (*f)(shell_data *shdata);
} built_in;
#endif /* smain.h */
