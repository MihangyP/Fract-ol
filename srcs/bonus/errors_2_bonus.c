/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:50:49 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:39:42 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

/* check if av[1] == "Mandelbrot"*/
int	is_mandelbrot(char *s)
{
	return (!ft_strncmp(s, "Mandelbrot", 10 + ft_strlen(s)));
}

/* check if av[1] == "Julia"*/
int	is_julia(char *s)
{
	return (!ft_strncmp(s, "Julia", 5 + ft_strlen(s)));
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '-')
		++i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (0);
		++i;
	}
	return (1);
}

void	handle_errors_next(char *name)
{
	if (is_julia(name))
		ft_putstr_fd("Usage: ./fractol Julia <number> <number>\n", 2);
	else
	{
		ft_putstr_fd("\033[0;31m\033[1mERROR\033[0m\n", 2);
		show_usage_message();
	}
	exit(EXIT_ERROR);
}
