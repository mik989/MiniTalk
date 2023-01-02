#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler()
{
	printf("Signal received\n");
}
int main()
{
	struct sigaction	sa_signal;
	int pid;
	pid = getpid();
	sa_signal.sa_sigaction = handler;
	printf("PID is : %d\n", pid);
	sigaction(SIGUSR1, &sa_signal, NULL);
}