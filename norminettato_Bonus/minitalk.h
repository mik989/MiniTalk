#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/include/libft.h"
# include <signal.h>
# include <stdlib.h>

typedef struct s_client 
{
    char		c;
	int k;
	int	s_pid;
	char	*s_str;
	int	i;
}	t_client;

void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int	send_null(int pid);
void ft_init(t_client *i);


#endif