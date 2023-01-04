#include "minitalk.h"

void handler(int signal, siginfo_t *info, void *cazzo)
{
	(void) info;
	(void) cazzo;
	static char c = 0;
	static int bit = 7;
	//usleep(3);
	if (signal == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (signal == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	if(bit-- == 0)
	{
		bit = 7;
		write(1, &c, 1);
		c = 0;
	}
	
	kill(info->si_pid, SIGUSR1);
	//usleep(3);

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