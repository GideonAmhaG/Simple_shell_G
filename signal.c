#include "sshell.h"
/**
 * sighandler - handles signals from keyboard interrupts
 * @sig: the signal caught
 */
void sighandler(int sig)
{
	unsigned char sig_flag = 0;

	if (sig == SIGINT && sig_flag == 0)
	{
		write(STDIN_FILENO, "\n", 1);
		write(STDIN_FILENO, "#cisfun$ ", 9);
	}
	else if (sig_flag != 0)
		write(STDIN_FILENO, "\n", 1);
}
