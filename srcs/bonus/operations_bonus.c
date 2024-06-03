/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:22 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:39:05 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/bonus/fractol_bonus.h"

/*
 * Add two complex number
 */
t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return (res);
}

/*
 * Square a complex number
 */
t_complex	square_complex(t_complex a)
{
	t_complex	res;

	res.r = (a.r * a.r) - (a.i * a.i);
	res.i = 2 * a.r * a.i;
	return (res);
}

/*
 * Convert a number (n) between 0 and p_max to a number between n_min & n_max 
 */
double	fit(double n, double n_min, double n_max, double p_max)
{
	double	fit_value;

	fit_value = (n_max - n_min) * n / p_max + n_min;
	return (fit_value);
}
