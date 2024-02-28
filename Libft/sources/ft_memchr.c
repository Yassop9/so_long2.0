/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:29:29 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	int				i;

	i = 0;
	d = (unsigned char *)s;
	while ((n--) > 0)
	{
		if (d[i] == (unsigned char)c % 256)
			return (d + i);
		i++;
	}
	return (0);
}
