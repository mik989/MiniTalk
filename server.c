#include "minitalk.h"

void handler(int signal, siginfo_t *info, void *cazzo)
{
	(void) info;
	(void) cazzo;
	if (signal == SIGUSR1)
	{
		write(1, "1", 1);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "0", 1);
	}

}
int main()
{
	struct sigaction	sa_signal;
	sigset_t			mask;
	int pid;

	sigemptyset(&mask);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGQUIT);
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = mask;
	sa_signal.sa_handler = 0;
	sa_signal.sa_sigaction = handler;
	pid = getpid();
	ft_printf("PID is : %d\n", pid);
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
	
}