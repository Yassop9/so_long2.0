/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:29:42 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest += n;
		src += n;
		while (n--)
			ft_memset(--dest, *(char *)(--src), sizeof(char));
	}
	return (dest);
}
