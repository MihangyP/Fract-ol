/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:50:46 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/01 17:03:58 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/bonus/fractol_bonus.h"

/*
 * Close Window and exit the program when we press ESC
 *  - Destroy the image
 *  - Destroy the Window
 *  - Destroy the Display created by mlx_init()
 *  - Destroy the Connexion 
 */
int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->con, fractol->img.img_ptr);
	mlx_destroy_window(fractol->con, fractol->win);
	mlx_destroy_display(fractol->con);
	free(fractol->con);
	free(fractol->name);
	exit(EXIT_SUCCESS);
	return (0);
}

/* event handler */
int	e_handler(int keysym, t_fractol *fractol)
{
	if (XK_Escape == keysym)
		close_window(fractol);
	if (XK_Right == keysym)
		fractol->shift_h += 0.5 * fractol->zoom;
	if (XK_Left == keysym)
		fractol->shift_h -= 0.5 * fractol->zoom;
	if (XK_Up == keysym)
		fractol->shift_v -= 0.5 * fractol->zoom;
	if (XK_Down == keysym)
		fractol->shift_v += 0.5 * fractol->zoom;
	if (XK_d == keysym)
		fractol->color_factor += 1;
	generate_fractol(fractol);
	return (0);
}

/*
 * Make the fractal 0.5 times bigger
 * Or 0.5 times smaller
 */
int	zoom_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractol->zoom *= 0.95;
	if (button == Button5)
		fractol->zoom *= 1.05;
	generate_fractol(fractol);
	return (0);
}

/* Listen events */
void	listen_events(t_fractol *fractol)
{
	mlx_hook(fractol->win,
		KeyPress,
		KeyPressMask,
		e_handler,
		fractol);
	mlx_hook(fractol->win,
		DestroyNotify,
		StructureNotifyMask,
		close_window,
		fractol);
	mlx_hook(fractol->win,
		ButtonPress,
		ButtonPressMask,
		zoom_handler,
		fractol);
}
