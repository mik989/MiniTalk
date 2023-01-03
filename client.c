#include "minitalk.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int pid;
		pid = ft_atoi(av[1]);
		kill(pid, SIGUSR1);
	}
}