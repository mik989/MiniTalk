/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:52:33 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/12 19:30:48 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(long int i)
{
	size_t	count;

	count = 0;
	if (i < 0)
	{
		i = i * -1;
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_logic(char *s, size_t count, size_t i, int n)
{
	while (count-- > i)
	{
		if (n < 0)
		{
			s[count] = '0' + (n % 10 * (-1));
			n = n / 10;
		}
		else
		{
			s[count] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	count;

	count = ft_count(n);
	s = (char *)malloc((count + 1));
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		i = 1;
	}
	else
		i = 0;
	ft_logic(s, count, i, n);
	return (s);
}
