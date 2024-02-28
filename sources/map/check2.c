/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:15:12 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/27 12:12:11 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_counts(t_count count)
{
	if (count.countp != 1)
		return (perror("Error: Invalid map - incorrect number of players"), 0);
	if (count.counte != 1)
		return (perror("Error: Invalid map - incorrect number of exits"), 0);
	if (count.countc == 0)
		return (perror("Error: Invalid map - no collectibles"), 0);
	ft_printf("Player: %d\nExit: %d\nCountc : %d\n ", count.countp,
			count.counte, count.countc);
	return (1);
}
