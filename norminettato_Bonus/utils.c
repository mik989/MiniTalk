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

	if (k-- != 0)
	{
		kill(pid, SIGUSR2);
		return (1);
	}
	return (0);
}

void ft_init(t_client *i)
{
	i->k = 8;
	i->s_pid = 0;
	i->i = 0;
}