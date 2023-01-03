#include "minitalk.h"

void handler()
{
	ft_printf("\U0001F60A\n");
	ft_printf("\U0000267B\n");
}
int main()
{
	struct sigaction	sa_signal;
	int pid;
	pid = getpid();
	sa_signal.sa_sigaction = handler;
	ft_printf("PID is : %d\n", pid);
	sigaction(SIGUSR1, &sa_signal, NULL);
	//while (1)
		pause();
	
}