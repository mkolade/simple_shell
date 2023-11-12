#include "smain.h"

/**
 * main - Main entry point
 * @ac: number of argument count
 * @av: number of argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	shell_data shdata;
	(void) ac;

	signal(SIGINT, getSignal);
	setData(&shdata, av);
	shellPrompt(&shdata);
	freeData(&shdata);
	if (shdata.status < 0)
		return (255);
	return (shdata.status);
}
