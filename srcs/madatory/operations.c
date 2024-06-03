/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:22 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 13:04:24 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

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
