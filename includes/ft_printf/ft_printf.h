/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <pmihangy@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:19:43 by pmihangy          #+#    #+#             */
/*   Updated: 2024/03/25 09:46:54 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_str(char *s);
int		print_nbr(int nbr);
int		convert(char *str, va_list ap);
int		put_u(long nbr);
int		put_p(unsigned long long n);
void	ft_put_u_nbr(unsigned int n, int fd, int *nbr_chars);
void	ft_putchar(char c, int *nbr_chars);
void	print_in_hex(unsigned long nbr, char c, int *nbr_chars);

#endif
