/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:21:48 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 12:43:42 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_BONUS_H
# define CONSTANTS_BONUS_H

/* mlx error return value */
# define MLX_ERROR 1

/* exit error && exit success return value */
# define EXIT_ERROR 69

/* some colors in hex */
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define ORANGE 0xFFC107
# define MAGENTA 0xF037A5

/* Window width an height */
# define W_WIDTH 800
# define W_HEIGHT 800

/* Some max iterations value */
enum	e_max_iteration
{
	MAX_ITER_MIN = 50,
	MAX_ITER_AVERAGE = 100,
	MAX_ITER_MAX = 200
};

#endif
