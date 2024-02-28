/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-yag <yben-yag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:04:26 by unix              #+#    #+#             */
/*   Updated: 2024/02/16 13:04:20 by yben-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/ft_printf.h"

static char	*up_or_lower(const char type)
{
	static char	*hex_chars_upper;
	static char	*hex_chars;

	hex_chars_upper = "0123456789ABCDEF";
	hex_chars = "0123456789abcdef";
	if (type == 'x')
		return (hex_chars);
	else
		return (hex_chars_upper);
}

char	*ft_generate_hex_string(unsigned int num, const char *format,
		int *print_length)
{
	int		i;
	char	*reversed_hex;

	i = 0;
	reversed_hex = malloc(sizeof(char) * 1000);
	if (!reversed_hex)
		return (NULL);
	while (num != 0)
	{
		reversed_hex[i] = format[num % 16];
		num /= 16;
		i++;
		(*print_length)++;
	}
	return (reversed_hex);
}

int	ft_print_hex(unsigned int num, const char format)
{
	char	*hex_digits;
	int		print_length;
	char	*reversed_hex;
	int		i;

	print_length = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex_digits = up_or_lower(format);
	reversed_hex = ft_generate_hex_string(num, hex_digits, &print_length);
	if (!reversed_hex)
		return (0);
	i = print_length;
	while (i-- > 0)
		write(1, &reversed_hex[i], 1);
	free(reversed_hex);
	return (print_length);
}
