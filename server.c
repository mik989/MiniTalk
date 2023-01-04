#include "minitalk.h"
static volatile int signalPid = -1;
void handler(int signal, siginfo_t *info, void *cazzo)
{
	signalPid = info->si_pid;
	(void) info;
	(void) cazzo;
	if (signal == SIGUSR1)
	{
		write(1, "1", 1);	
		write(1, "\n", 1);				
		ft_printf("kill USR1 is : %d\n", kill(signalPid, SIGUSR1));
		ft_printf("signalPid USR1 is : %d\n", signalPid);
		
	}
	else if (signal == SIGUSR2)
	{
		write(1, "0", 1);
		write(1, "\n", 1);		
		ft_printf("kill USR2 is : %d\n", kill(signalPid, SIGUSR2));
		ft_printf("signalPid USR2 is : %d\n", signalPid);	
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
	ft_printf("signalPid is : %d\n", signalPid);
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
	
}