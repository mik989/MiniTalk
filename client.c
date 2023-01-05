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
int	send_null(int pid)
{
	static int	k = 8;
	if(k-- != 0)
	{
		kill(pid, SIGUSR2);
		return(1);
	}
	return(0);
		
}
void	send(int pid, char *str)
{
	char		c;
	static int	k = 8;
	static int	s_pid = 0;
	static char	*s_str;
	static int	i = 0;

	if (pid)
		s_pid = pid;
	if (str)
		s_str = ft_strdup(str);
	if (!s_str[i])
	{
		if (send_null(s_pid) == 0)
		{
		free(s_str);
		ft_printf("Message sent\n");
		exit(0);
		}
	}
	if (k-- && s_str[i])
	{	
		c = (s_str[i] >> k) & 1;
		if (c)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
	}
	if (k == 0 && s_str[i])
	{
		i++;
		k = 8;
	}
	return ;
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

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		send(pid, av[2]);
		while (1)
			pause();
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}
