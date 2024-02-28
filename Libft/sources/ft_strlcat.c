/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:30:31 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	supp_len;

	supp_len = 0;
	src_len = ft_strlen((char *)src);
	while (size > 0 && *dst)
	{
		dst++;
		supp_len++;
		size--;
	}
	while (size-- > 1 && *src)
		*dst++ = *src++;
	if (size == 0 || !*src)
		*dst = '\0';
	return (src_len + supp_len);
}
