#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int pid = atoi(av[1]);
	kill(pid, SIGUSR1);
}