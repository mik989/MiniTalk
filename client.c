#include "minitalk.h"

static volatile int control = -1;

void handler(int signal, siginfo_t *info, void *cazzo)
{
	(void) info;
	(void) cazzo;
	if (signal == SIGUSR1)
		control = 1;
	else if (signal == SIGUSR2)
		control = 0;
}

int main(int ac, char **av)
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
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);

	int i;
	int k;
	int pidC = getpid();
	int trigger = 1;
	int c = 0;

	i = 0;
	if (ac == 3)
	{
		ft_printf("My PID is : %d\n", pidC);
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			k = 8;
			while((k-- && c == control) || trigger == 1)
			{
				c = (av[2][i] >> k) & 1;	
					if (c)
					{
						
						kill(pid, SIGUSR1);				
					}
					else
					{	
						kill(pid, SIGUSR2);			
					}
				usleep(3);
				trigger = 0;				
			}
			i++;
		}

	while (1)
		pause();
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}