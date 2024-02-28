/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:30:14 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

static void	ft_free_all(char **new_str)
{
	int	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		new_str[i] = NULL;
		i++;
	}
	free(new_str);
}

static char	**ft_allocate(char **new_str, const char *str, char separator)
{
	const char	*tmp_str;
	char		**tmp_new_str;

	tmp_new_str = new_str;
	tmp_str = str;
	while (*tmp_str)
	{
		while (*str == separator)
			str++;
		tmp_str = str;
		while (*tmp_str && *tmp_str != separator)
			tmp_str++;
		if (*tmp_str == separator || tmp_str > str)
		{
			*tmp_new_str = ft_substr(str, 0, tmp_str - str);
			if (!*tmp_new_str)
				return (ft_free_all(tmp_new_str), NULL);
			str = tmp_str;
			tmp_new_str++;
		}
	}
	*tmp_new_str = NULL;
	return (new_str);
}

static int	ft_count_words(const char *str, char separator)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		if (*str)
			count++;
		while (*str && *str != separator)
			str++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**new_str;

	if ((!s && (c == ' ')))
		return (NULL);
	new_str = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!new_str)
		return (NULL);
	new_str = ft_allocate(new_str, s, c);
	return (new_str);
}
