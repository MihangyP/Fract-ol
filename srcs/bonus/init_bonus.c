/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:57:19 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:38:31 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/bonus/fractol_bonus.h"

/*
 *  Create an image 
 *	Get related data
 */
static void	init_img(t_fractol *fractol)
{
	fractol->img.img_ptr = mlx_new_image(fractol->con, W_WIDTH, W_HEIGHT);
	fractol->img.img_pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp,
			&fractol->img.line_len,
			&fractol->img.endian);
}

static void	set_params(t_fractol *fractol, int ac, char **av)
{
	fractol->zoom = 1.0;
	fractol->shift_h = 0.0;
	fractol->shift_v = 0.0;
	fractol->color_factor = 5;
	if (!ft_strncmp(fractol->name, "Julia", 69))
	{
		if (ac == 2)
		{
			fractol->j_r = 0.285;
			fractol->j_i = 0.01;
		}
		else if (ac == 4)
		{
			fractol->j_r = atod(av[2]);
			fractol->j_i = atod(av[3]);
		}
	}
	else
	{
		fractol->j_r = 0.0;
		fractol->j_i = 0.0;
	}
}

/*
 * Initialise the Fractol
 * Make connection with the X server
 * Create the Window
 * Create the Image
 * Set zoom_factor to 1.0
 * Set shift_v & shift_h to 0.0
 */
void	init(t_fractol *fractol, int ac, char **av)
{
	fractol->con = mlx_init();
	if (NULL == fractol->con)
	{
		free(fractol->con);
		exit(EXIT_ERROR);
	}
	fractol->name = ft_strdup(av[1]);
	fractol->win = mlx_new_window(fractol->con, W_WIDTH, W_HEIGHT,
			fractol->name);
	if (NULL == fractol->win)
	{
		mlx_destroy_display(fractol->con);
		free(fractol->con);
		exit(EXIT_ERROR);
	}
	init_img(fractol);
	set_params(fractol, ac, av);
}
