/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:30:21 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;

	len = ft_strlen(s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	len = 0;
	while (s[len])
	{
		result[len] = s[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}
