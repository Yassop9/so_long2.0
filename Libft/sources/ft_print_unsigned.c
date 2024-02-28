/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:59:09 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num / 10)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	int		len;
	char	*num;

	print_length = 0;
	len = ft_num_len(n);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (0);
	num[len] = '\0';
	while (len > 0)
	{
		len--;
		num[len] = (n % 10) + '0';
		n = n / 10;
	}
	print_length += write(1, num, ft_strlen(num));
	free(num);
	return (print_length);
}
