#include "minitalk.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, len);
	return (s2);
}
void send(int pid, char *str)
{
	char c;
	static int k = 8;
	static int s_pid = 0;
	static char *s_str;

	if (pid)
		s_pid = pid;
	if (str)
		s_str = ft_strdup(str);
	if (!*s_str)
	{
		free(s_str);
		exit(0);
	}
	if (k--)
	{	
		c = (*s_str >> k) & 1;
		if(c)
		{
			kill(s_pid, SIGUSR1);
		}
		else
		{
			kill(s_pid, SIGUSR2);
		}
		//return;
		//usleep(3);
		//pause();
	}
	if (k == 0)
	{
		s_str++;
		k = 8;
	}
	return;
}

void	handler(int sign)
{
	if (sign == SIGUSR1)
	{
		send(0, 0);
	}
	else if (sign == SIGUSR2)
	{
		exit(0);
	}
}

int main(int ac, char **av)
{
	//int i;
	//int k;
	//char c;

//	i = 0;
	if (ac == 3)
	{
		int pid;
		pid = ft_atoi(av[1]);
		/*while (av[2][i])
		{
			k = 8;
			while(k--)
			{
				c = (av[2][i] >> k) & 1;
				if(c)
				{
					kill(pid, SIGUSR1);
				}
				else
				{
					kill(pid, SIGUSR2);
				}
				usleep(3);
			}
			i++;
		}*/
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		send(pid, av[2]);
		while (1)
		{
			pause();
		}
		
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}