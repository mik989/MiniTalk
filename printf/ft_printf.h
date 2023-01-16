/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:01:43 by mgirardi          #+#    #+#             */
/*   Updated: 2022/10/21 20:05:23 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_s(char *c);
int	ft_print_c(char c);
int	ft_print_p(uintptr_t ptr, int fd);
int	printf_putchar_fd(char c, int fd);
int	printf_putstr_fd(char *s, int fd);
int	printf_putnbr_fd(int nb, int fd);
int	ft_putnbr_baseu_fd(unsigned int nbr, int fd);
int	ft_putnbr_basex_fd(unsigned int nbr, int fd, int lowercase);
int	ft_putnbr_basep_fd(unsigned long int nbr, int fd, char *base);

#endif
