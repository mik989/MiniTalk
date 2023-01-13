#include "minitalk.h"

void send_print(t_client client_i)
{
	free(client_i.s_str);
	ft_printf("Message sent\n");
	exit(0);
}

void	ft_send_signals(t_client client_i)
{
	client_i.c = (client_i.s_str[client_i.i] >> client_i.k) & 1;
		if (client_i.c)
			kill(client_i.s_pid, SIGUSR1);
		else
			kill(client_i.s_pid, SIGUSR2);
}

void	send(int pid, char *str)
{
	t_client client_i;

	client_i.k = 8;
	client_i.s_pid = 0;
	client_i.i = 0;
	if (pid)
		client_i.s_pid = pid;
	if (str)
		client_i.s_str = ft_strdup(str);
	if (client_i.s_str[client_i.i] == '\0')
	{
		if (send_null(client_i.s_pid) == 0)
			send_print(client_i);
	}
	if (client_i.k-- && client_i.s_str[client_i.i])
		ft_send_signals(client_i);
	if (client_i.k == 0 && client_i.s_str[client_i.i])
	{
		client_i.i++;
		client_i.k = 8;
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
