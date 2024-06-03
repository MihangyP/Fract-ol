/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:32:48 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/01 14:08:52 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol/madatory/fractol.h"

/*============================================================================
 * 1. Manage Errors													
 * 2. Initialise mlx														
 *    - Create connexion with the server
 *    - Create a Window
 *    - Create an Image
 * 3. Generate the fractol
 * 4. Listen Events like (Press ESC, Zoom, Shift right, Shift left, ...)
 * 
 *==========================================================================*/
int	main(int ac, char **av)
{
	t_fractol	fractol;

	handle_errors(ac, av);
	init(&fractol, ac, av);
	generate_fractol(&fractol);
	listen_events(&fractol);
	mlx_loop(fractol.con);
	return (0);
}
