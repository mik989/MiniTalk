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

char	*join_char(char c, char *str)
{
	int	i;
	char *joint;

	i = 0;
	//i = ft_strlen(str);
	if (!*str && c)
	{
		joint = malloc(sizeof(char) * 2);
		joint[0] = c;
		joint[1] = '\0';
		return (joint);
	}
	else if (*str && c)
	{
		i = ft_strlen(str);
		joint = malloc(sizeof(char) * (i + 2));
		joint = ft_memcpy(joint, str, i);
		joint[i] = c;
		joint[i + 1] = '\0';
		free(str);
	}
	else
		return (NULL);
	
	return (joint);	
}

void	handler(int signal, siginfo_t *info, void *cazzo)
{
	static char	c = 0;
	static int	bit = 7;
	static char	*text = "\0";

	(void) cazzo;
	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1) | 0;
	if (bit-- == 0)
	{
		bit = 7;
		if (c)
			text = join_char(c, text);
		else
		{
			ft_printf("%s\n", text);
			free(text);
			text = "\0";
			ft_printf("\U0001F601 \n");
		}
		//write(1, &c, 1);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			mask;
	int					pid;

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
