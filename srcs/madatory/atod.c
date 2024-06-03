/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:26:21 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 13:29:51 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

/* Check if a character is a space */
static int	is_spaces(const char c)
{
	return (c == 32 || (c > 8 && c < 14));
}

/* Continuation of conversion from string to a double */
static void	atod_next(char *nptr, double *num, int i)
{
	double	decimal;

	decimal = 1.0;
	while (nptr[i] == '.')
	{
		i++;
		while (ft_isdigit(nptr[i]))
		{
			decimal = decimal * 0.1;
			(*num) += (nptr[i] - '0') * decimal;
			i++;
		}
	}
}

/* Convert a string to a double */
double	atod(const char *nptr)
{
	double	neg;
	double	num;
	int		i;

	i = 0;
	neg = 1.0;
	num = 0.0;
	while (is_spaces(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1.0;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10.0 + (nptr[i] - '0');
		i++;
	}
	atod_next((char *)nptr, &num, i);
	return (num * neg);
}
