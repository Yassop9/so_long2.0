/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:16:06 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/ft_printf.h"

int	ft_printnbr(int n)
{
	int	i;
	int	sign;

	sign = 0;
	i = 1;
	if (n < 0)
		sign = 1;
	ft_putnbr_fd(n, 1);
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i + sign);
}
