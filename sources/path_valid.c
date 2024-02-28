/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:07:34 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/25 12:40:19 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(char **map, int x, int y, int *visited, int width, int height,
		int *collectibles_count, int *monsters_count)
{
	if (x < 0 || y < 0 || x >= width || y >= height || visited[y * width + x]
		|| map[y][x] == '1')
		return (0);
	visited[y * width + x] = 1;
	if (map[y][x] == 'C')
		(*collectibles_count)++;
	if (map[y][x] == 'M')
		(*monsters_count)++;
	flood_fill(map, x + 1, y, visited, width, height, collectibles_count,
		monsters_count);
	flood_fill(map, x - 1, y, visited, width, height, collectibles_count,
		monsters_count);
	flood_fill(map, x, y + 1, visited, width, height, collectibles_count,
		monsters_count);
	flood_fill(map, x, y - 1, visited, width, height, collectibles_count,
		monsters_count);
	return (1);
}
