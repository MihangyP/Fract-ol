/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:52:34 by pmihangy          #+#    #+#             */
/*   Updated: 2024/05/29 11:41:57 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

void	handle_errors(int ac, char **av);
void	handle_errors_next(char *name);
void	show_usage_message(void);
int		is_valid(char *s);
int		is_mandelbrot(char *s);
int		is_julia(char *s);

#endif
