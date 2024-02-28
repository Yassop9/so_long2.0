/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:18:27 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/ft_printf.h"

int	ft_printstr(char *str)
{
	size_t	len_str;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len_str = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len_str);
}
