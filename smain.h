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

/*change_dir.c*/
int cd_dir(shell_data *shdata);
void cd_per(shell_data *shdata);
void cd_goto(shell_data *shdata);
void cd_go_back(shell_data *shdata);
void cd_home(shell_data *shdata);

/*check_input.c*/
void check_env_var(store_var **h, char *in, shell_data *data);
int check_var_typed(store_var **h, char *in, char *st, shell_data *data);
char *replace_str_var(store_var **head,
		char *input, char *new_input, int nlen);
char *rep_str_var(char *input, shell_data *shdata);

/*conver_string.c*/
int get_len(int n);
char *int_to_string(int n);
int _atoi(char *s);
char *without_comment(char *in);
void cmd_help(void);
void aux_help_alias(void);
void change_cd_help(void);
void rev_string(char *s);

/*div_list.c*/
store_var *add_store_var_node(store_var **head,
		int var_length, char *value, int value_length);
void free_store_var_list(store_var **head);
div_list *add_div_node_end(div_list **head, char sep);
void free_div_list(div_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
#endif /* smain.h */
