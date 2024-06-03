/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:48:30 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:31:23 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

/*
 * Display the usage message as its name suggests.
 */
void	show_usage_message(void)
{
	ft_putstr_fd("Usage: ./fractol <fractol_type> [parameters]\n", 2);
	ft_putstr_fd("Available Fractol Types:\n", 2);
	ft_putstr_fd("\t- Mandelbrot\n\t- Julia\n", 2);
}

/* 
 * Manage errors specially for Julia set
 */
static void	handle_julia_errors(char **av)
{
	if (ft_strncmp(av[1], "Julia", 5 + ft_strlen(av[1])))
	{
		ft_printf("\033[0;31m\033[1mERROR\033[0m\n");
		show_usage_message();
		exit(EXIT_ERROR);
	}
	if (!is_valid(av[2]) || !is_valid(av[3]))
	{
		ft_putstr_fd("Usage: ./fractol Julia <number> <number>\n", 2);
		exit(EXIT_ERROR);
	}
}

/* Check if av[1] == "Burning-Ship" */
static int	is_burning(char *s)
{
	return (!ft_strncmp(s, "Burning-Ship", 10 + ft_strlen(s)));
}

/*
 * Show error message when :
 * - Missing Argument
 * - Invalid Argument
 * - Missign Parameters (Julia)
 */
void	handle_errors(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("\033[0;31m\033[1mERROR\033[0m: Missing argument.\n", 2);
		show_usage_message();
		exit(EXIT_ERROR);
	}
	else if (ac == 2)
	{
		if (!is_mandelbrot(av[1]) && !is_julia(av[1]) && !is_burning(av[1]))
		{
			ft_putstr_fd("\033[0;31m\033[1mERROR\033[0m\n", 2);
			show_usage_message();
			exit(EXIT_ERROR);
		}
	}
	else if (ac == 4)
		handle_julia_errors(av);
	else
		handle_errors_next(av[1]);
}
