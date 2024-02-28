/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:29:37 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				n;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	n = -1;
	if (size == 0 || dest == src)
		return (dest);
	while (++n < size)
		d[n] = s[n];
	return (dest);
}
