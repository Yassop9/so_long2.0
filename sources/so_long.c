/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:01:34 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/27 13:52:52 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_and_run_game(char *background_path)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nMLX initialization failed\n");
		exit(1);
	}
	data.mlx_win = mlx_new_window(data.mlx, 928, 793, "so_long");
	if (!data.mlx_win)
	{
		perror("Error\nFailed to create window\n");
		exit(1);
	}
	data.img = mlx_xpm_file_to_image(data.mlx, background_path, &data.width,
			&data.height);
	if (!data.img)
	{
		perror("Error\nFailed to load background image\n");
		exit(1);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	t_map	*map;
	char	*map_path;
	int		height;
	int		width;

	t_count count;
	if (ac != 2)
	{
		return (perror("Error\nInvalid number of arguments\n"), 1);
	}
	map_path = av[1];
	if (!get_map_dimensions(map_path, &height, &width))
		return (perror("Error\nFailed to determine map dimensions\n"), 1);
	map = create_map(height, width);
	if (!map)
	{
		free_map_structure(&map);
		return (perror("Error\nFailed to create map\n"), 1);
	}
	if (!load_map_from_file(map, map_path))
	{
		perror("Error loading map from file");
		free_map_structure(&map);
		return (EXIT_FAILURE);
	}
	count_elements_in_map(map->map, &count);
	if (!validate_counts(count))
	{
		ft_printf("Erreur lors de la validation de la carte.\n");
		free_map_structure(&map);
		return (EXIT_FAILURE);
	}
	if (!validate_game_map(map, map_path))
	{
		ft_printf("Erreur lors de la validation de la carte.\n");
		free_map_structure(&map);
		return (EXIT_FAILURE);
	}
	else
		initialize_and_run_game("./sprite/Background.xpm");
	free_map_structure(&map);
	return (0);
}
