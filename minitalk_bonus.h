/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:43:12 by mgirardi          #+#    #+#             */
/*   Updated: 2023/01/16 18:43:14 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include	"printf/ft_printf.h"
# include	"libft/libft.h"
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
