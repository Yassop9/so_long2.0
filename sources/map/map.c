/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:48:36 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/27 14:18:53 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map_lines(t_map *map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		map->map[i] = (char *)ft_calloc((width + 1), sizeof(char));
		if (!map->map[i])
		{
			while (--i >= 0)
				free(map->map[i]);
			free(map->map);
			return (0);
		}
		i++;
	}
	map->map[height] = NULL;
	return (1);
}

t_map	*create_map(int height, int width)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = height;
	map->width = width;
	map->map = ft_calloc((height + 1), sizeof(char *));
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	if (!init_map_lines(map, height, width))
	{
		free_map_structure(&map);
		return (NULL);
	}
	return (map);
}

void	free_map_structure(t_map **map)
{
	int	i;

	if (!map || !*map)
		return ;
	if ((*map)->map)
	{
		i = 0;
		while ((*map)->map[i])
		{
			free((*map)->map[i]);
			i++;
		}
		free((*map)->map);
	}
	free(*map);
	*map = NULL;
}

int	get_map_dimensions(const char *map_path, int *height, int *width)
{
	int		fd;
	char	*line;

	*height = 0;
	*width = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (*width == 0)
			*width = ft_strlen(line);
		(*height)++;
		free(line);
	}
	close(fd);
	return (1);
}

int	load_map_from_file(t_map *map, const char *filename)
{
	int		fd;
	char	*line;
	int		y;

	printf("Chargement de la carte à partir du fichier %s\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Erreur lors de l'ouverture du fichier"), 0);
	y = 0;
	while ((line = get_next_line(fd)) != NULL && y < map->height)
	{
		printf("Ligne %d: %s", y, line);
		ft_strlcpy(map->map[y], line, map->width);
		map->map[y][map->width] = '\0';
		free(line);
		y++;
	}
	close(fd);
	return (1);
}

int	validate_map_walls_and_size(t_map *map)
{
	int	y;

	y = 0;
	if (!is_wall_line(map->map[0]))
		return (perror("Le mur supérieur n'est pas valide"), 0);
	y = 1;
	while (y < map->height - 1)
	{
		if (!is_wall_enclosed_line(map->map[y]))
			return (printf("Ligne non encadrée par des murs: %s\n",
					map->map[y]), 0);
		y++;
	}
	if (!is_wall_line(map->map[map->height - 1]))
		return (perror("Le mur inférieur n'est pas valide"), 0);
	return (1);
}

int	validate_game_map(t_map *map, const char *map_path)
{
	t_count	count;
	int		fd;

	printf("Début de la validation de la carte %s\n", map_path);
	count_elements_in_map(map->map, &count);
	if (!check_file_extension((char *)map_path, ".ber"))
		return (perror("Extension de fichier invalide"), 0);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (perror("Erreur lors de l'ouverture du fichier de la carte"), 0);
	if (!validate_counts(count))
		return (close(fd), 0);
	if (!load_map_from_file(map, map_path))
		return (perror("Impossible de charger la carte à partir du fichier"),
				0);
	if (!validate_map_walls_and_size(map))
		return (0);
	return (1);
}
