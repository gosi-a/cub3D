/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:38:05 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/18 18:44:21 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static	int	move_player(t_root*data, float delta_x,	float delta_y)
{
	float	new_x;
	float	new_y;
	int		map_x;
	int		map_y;

	map_x = 0;
	map_y = 0;
	
	new_x = data->p->x_pos + delta_x;
	new_y = data->p->y_pos + delta_y;
	map_x = (int)new_x;
	map_y = (int)new_y;

	if(data->map->map[map_y][map_x] == '0')
	{
		data->p->x_pos = new_x;
		data->p->y_pos = new_y;
		printf("Player moved to: [%f][%f]\n", data->p->y_pos, data->p->x_pos);
		return (1);
	}
	else
		{
			printf("Hit the wall\n");
			return 0;
		}
}

static void go_forward(t_root *data)
{
	printf("Going forward\n");
	move_player(data, 0.0, -0.1);
}
static void go_backward(t_root *data)
{
	printf("Going backward\n");
	move_player(data, 0.0, 0.1);
}
static void turn_left(t_root *data)
{
	printf("Going left\n");
	move_player(data, -0.1, 0.0);
}
static void turn_right(t_root *data)
{
	printf("Going right\n");
	move_player(data, 0.1, 0.0);
}


void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_root	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		go_forward(data);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		go_backward(data);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		turn_left(data);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		turn_right(data);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->cub_mlx.win);;
	add_mini_map(data);
	// if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_W))
	// 	go_forward(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_S))
	// 	go_backward(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_A))
	// 	turn_left(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_D))
	// 	turn_right(data);
	// else if (mlx_is_key_down(data->cub_mlx.win, MLX_KEY_ESCAPE))
	// 	close_game(data);
}
