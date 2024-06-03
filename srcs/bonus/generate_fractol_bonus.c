/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_fractol_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:51 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:53 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/bonus/fractol_bonus.h"

/* Put a color in a specific piexel */
void	put_color_pixel(t_img	*img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*(unsigned int *)(offset + img->img_pixels_ptr) = color;
}

static void	init_zc(t_fractol *fractol, t_point p, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(fractol->name, "Mandelbrot", 69))
	{
		z->r = 0.0;
		z->i = 0.0;
		c->r = fit(p.x, -2, 2, W_WIDTH) * fractol->zoom + fractol->shift_h;
		c->i = fit(p.y, 2, -2, W_HEIGHT) * fractol->zoom + fractol->shift_v;
	}
	else if (!ft_strncmp(fractol->name, "Burning-Ship", 69))
	{
		z->r = 0.0;
		z->i = 0.0;
		c->r = fit(p.x, -2, 2, W_WIDTH) * fractol->zoom + fractol->shift_h;
		c->i = fit(p.y, -2, 2, W_HEIGHT) * fractol->zoom + fractol->shift_v;
	}
	else
	{
		z->r = fit(p.x, -2, 2, W_WIDTH) * fractol->zoom + fractol->shift_h;
		z->i = fit(p.y, 2, -2, W_HEIGHT) * fractol->zoom + fractol->shift_v;
		c->r = fractol->j_r;
		c->i = fractol->j_i;
	}
}

static void	fabs_z(t_fractol *fractol, t_complex *z)
{
	if (!ft_strncmp(fractol->name, "Burning-Ship", 69))
	{
		z->r = fabs(z->r);
		z->i = fabs(z->i);
	}
}

/*
 * Color each pixel with the corresponding color
 * Mandelbrot :
 *  Une fractale definie comme l'ensemble des points c du plan complexe
 *  pour lesquels la suite de nombres definie par recurrence par :
 *  z(0) = 0
 *  z(n + 1) = z(n)^2 + c
 *  est bornee
 * Julia
 * ????
 */
static void	put_in_image(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_point		p;
	int			i;
	int			color;

	p.x = x;
	p.y = y;
	init_zc(fractol, p, &z, &c);
	i = 0;
	while (i < MAX_ITER_MIN)
	{
		fabs_z(fractol, &z);
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			color = fit(i * fractol->color_factor,
					(BLACK + 5) * 10, WHITE, MAX_ITER_MIN);
			put_color_pixel(&fractol->img, x, y, color);
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
		while (w < W_HEIGHT)
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
