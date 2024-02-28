/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:30:59 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len + start > slen)
		len = slen - start;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
