/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:43:26 by mgirardi          #+#    #+#             */
/*   Updated: 2023/01/16 18:43:28 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_init(t_client *i)
{
	i->k = 8;
	i->s_pid = 0;
	i->i = 0;
}
