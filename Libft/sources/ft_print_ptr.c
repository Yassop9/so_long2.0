/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:03:36 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/ft_printf.h"

void	ft_print_ptr_helper(unsigned long ptr)
{
	char	*hex_chars;
	char	*hex;
	int		index;

	index = 0;
	hex_chars = "0123456789abcdef";
	hex = malloc(sizeof(char) * 17);
	if (!hex)
		return ;
	else
	{
		while (ptr > 0)
		{
			hex[index] = hex_chars[ptr % 16];
			ptr /= 16;
			index++;
		}
		index--;
		while (index >= 0)
		{
			ft_putchar_fd(hex[index], 1);
			index--;
		}
	}
	free(hex);
}

int	ft_count_digits_base(unsigned long m, int l)
{
	int	i;

	i = 0;
	while (m > 0)
	{
		m /= l;
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	print_length;

	print_length = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		print_length = ft_strlen("(nil)");
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_print_ptr_helper(ptr);
		print_length = ft_count_digits_base(ptr, 16) + 2;
	}
	return (print_length);
}
