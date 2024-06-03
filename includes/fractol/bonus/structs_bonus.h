/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:35 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:42:53 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

/* mlx img 
 *  - img pointer
 *  - img pixels pointer
 *  - bits per pixel
 *  - endian
 *  - line line
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

/* mlx data */
typedef struct s_fractol
{
	void	*con;
	void	*win;
	t_img	img;
	double	zoom;
	double	shift_h;
	double	shift_v;
	double	j_r;
	double	j_i;
	int		color_factor;
	char	*name;
}	t_fractol;

/* Complexe number*/
typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

/* Point */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
