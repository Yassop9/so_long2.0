/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassop <yassop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:21:26 by yben-yag          #+#    #+#             */
/*   Updated: 2024/02/27 13:14:28 by yassop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(0);
	return (0);
}
