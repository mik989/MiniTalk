#include "minitalk.h"

t_client	*g_client;

void	send_print(t_client *g_client)
{
	free(g_client->s_str);
	free(g_client);
	ft_printf("Message sent\n");
	exit(0);
}

void	ft_send_signals(t_client *g_client)
{
	g_client->c = (g_client->s_str[g_client->i] >> g_client->k) & 1;
	if (g_client->c)
		kill(g_client->s_pid, SIGUSR1);
	else
		kill(g_client->s_pid, SIGUSR2);
}

void	send(int pid, char *str, t_client *g_client)
{
	if (pid)
		g_client->s_pid = pid;
	if (str)
		g_client->s_str = ft_strdup(str);
	if (!g_client->s_str[g_client->i])
	{
		if (send_null(g_client->s_pid) == 0)
			send_print(g_client);
	}
	if (g_client->k-- && g_client->s_str[g_client->i])
		ft_send_signals(g_client);
	if (g_client->k == 0 && g_client->s_str[g_client->i])
	{
		g_client->i++;
		g_client->k = 8;
	}
	return ;
}

void	handler(int sign)
{
	if (sign == SIGUSR1)
	{
		send(0, 0, g_client);
	}
	else if (sign == SIGUSR2)
	{
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	g_client = malloc(sizeof(t_client));
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_init(g_client);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		send(pid, av[2], g_client);
		while (1)
			pause();
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}
