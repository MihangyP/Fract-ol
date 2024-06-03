/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <pmihangy@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:48:12 by pmihangy          #+#    #+#             */
/*   Updated: 2024/03/13 09:40:59 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_tmp;

	i = 0;
	s_tmp = (char *)s;
	while (i < n)
	{
		if (s_tmp[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
