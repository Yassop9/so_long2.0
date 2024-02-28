/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/27 16:36:25 by yben-yag          #+#    #+#             */
/*   Updated: 2023/11/27 16:36:25 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*end;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	if (size > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	end = malloc(nmemb * size);
	if (!end)
		return (NULL);
	ft_bzero(end, nmemb * size);
	return (end);
}
