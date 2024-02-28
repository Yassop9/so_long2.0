/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/27 16:36:45 by yben-yag          #+#    #+#             */
/*   Updated: 2023/11/27 16:36:45 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"

static char	*int_to_char(char *nbr, int malo, int token, int n)
{
	nbr[malo + token + 1] = '\0';
	while (malo > -1)
	{
		nbr[malo + token] = (n % 10) + '0';
		n = n / 10;
		malo = malo - 1;
	}
	if (token == 1)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		copy_n;
	int		token;
	int		malo;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		token = 1;
		n = n * (-1);
	}
	else
		token = 0;
	malo = 0;
	copy_n = n;
	while (copy_n > 9)
	{
		copy_n = copy_n / 10;
		malo = malo + 1;
	}
	nbr = malloc(sizeof(char) * (malo + token + 2));
	if (nbr == NULL)
		return (NULL);
	return (int_to_char(nbr, malo, token, n));
}
