/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:11:29 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/27 13:09:41 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_elements_in_map(char **map, t_count *count)
{
	int	y;
	int	x;

	y = 0;
	count->countc = 0;
	count->countp = 0;
	count->counte = 0;
	count->countm = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				count->countc++;
			else if (map[y][x] == 'P')
				count->countp++;
			else if (map[y][x] == 'E')
				count->counte++;
			else if (map[y][x] == 'M')
				count->countm++;
			x++;
		}
		y++;
	}
}

int	check_file_extension(char *filename, char *extension)
{
	int	len;
	int	ext_len;
	int	offset;

	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	offset = len - ext_len;
	if (len <= ext_len)
		return (0);
	return (ft_strncmp(filename + offset, extension, ext_len) == 0);
}

int	is_wall_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_wall_enclosed_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len < 2)
		return (0);
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}
