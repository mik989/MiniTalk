#include "minitalk.h"

int main(int ac, char **av)
{
	int i;
	int k;
	char c;

	i = 0;
	if (ac == 3)
	{
		int pid;
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			k = 8;
			while(k--)
			{
				c = (av[2][i] >> k) & 1;
				if(c)
				{
					kill(pid, SIGUSR1);
					sleep(1);
				}
				else
				{
					kill(pid, SIGUSR2);
					sleep(1);
				}
			}
			i++;
		}
		
		//kill(pid, SIGUSR1);
		//kill(pid, SIGUSR1);
		//kill(pid, SIGUSR1);
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}