/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:07:51 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/12 14:30:33 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = ft_strlen(little);
	while ((little[j] != '\0' && big[i] != '\0') && i < len)
	{
		if (little[j] == big[i])
			j++;
		else
			j = 0;
		i++;
	}
	if (x == 0)
		return ((char *)big);
	else if (j == x)
		return ((char *)&big[i - j]);
	else
		return (0);
}
