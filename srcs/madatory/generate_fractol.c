/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:51 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/01 17:04:53 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

/* Put a color in a specific pixel */
static void	put_color_pixel(t_img	*img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*(unsigned int *)(offset + img->img_pixels_ptr) = color;
}

/*
 * Convert a number (n) between 0 and p_max to a number between n_min & n_max 
 */
static double	fit(double n, double n_min, double n_max, double p_max)
{
	double	fit_value;

	fit_value = (n_max - n_min) * n / p_max + n_min;
	return (fit_value);
}

static void	init_zc(t_fractol *fractol, t_point p, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractol->name, "Mandelbrot", 69))
	{
		z->r = 0.0;
		z->i = 0.0;
		c->r = fit(p.x, -2, 2, W_WIDTH) * fractol->zoom;
		c->i = fit(p.y, 2, -2, W_HEIGHT) * fractol->zoom;
	}
	else
	{
		z->r = fit(p.x, -2, 2, W_WIDTH) * fractol->zoom;
		z->i = fit(p.y, -2, 2, W_HEIGHT) * fractol->zoom;
		c->r = fractol->j_r;
		c->i = fractol->j_i;
	}
}

/*
 * Color each pixel with the corresponding color based on
 * the chosen fractal and its parameters.
 *
 * Mandelbrot set:
 * - A fractal defined as the set of complex points 'c' for
 *   which the sequence of numbers defined recursively by:
 *   z(0) = 0
 *   z(n + 1) = z(n)^2 + c
 *   is bounded.
 *   Each 'c' corresponds to a pixel in the window.
 *
 * Julia set:
 * - Similar to Mandelbrot set, but 'c' is fixed (e.g., c = -0.8 + 0.156i).
 */
static void	put_in_image(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_point		p;
	int			i;

	p.x = x;
	p.y = y;
	init_zc(fractol, p, &z, &c);
	i = 0;
	while (i < MAX_ITER_MIN)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			put_color_pixel(&fractol->img, x, y, (BLACK + 6) * (i + 5));
			return ;
		}
		++i;
	}
	put_color_pixel(&fractol->img, x, y, BLACK);
}

/*
 * Draw the fractol
 */
void	generate_fractol(t_fractol *fractol)
{
	int	w;
	int	h;

	h = 0;
	while (h < W_HEIGHT)
	{
		w = 0;
		while (w < W_WIDTH)
		{
			put_in_image(w, h, fractol);
			++w;
		}
		++h;
	}
	mlx_put_image_to_window(fractol->con,
		fractol->win,
		fractol->img.img_ptr,
		0,
		0);
}
