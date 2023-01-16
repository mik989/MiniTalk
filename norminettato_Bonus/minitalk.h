#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>

typedef struct s_client
{
	char	c;
	int		k;
	int		s_pid;
	char	*s_str;
	int		i;
}	t_client;
int		send_null(int pid);
void	ft_init(t_client *i);

#endif