/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 10:49:30 by amysiv        #+#    #+#                 */
/*   Updated: 2025/02/04 10:20:24 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ceiling_rgb(char *str, t_root *data)
{
	char	**c_arg;

	c_arg = splitbywhite(str, ',');
	if (c_arg == NULL)
		return ;
	if (!c_arg[1] || !c_arg[2] || !c_arg[3])
		free_data_arr(data, ERR_TO_FEW_PARAM_C, c_arg);
	if (c_arg[4] != NULL)
		free_data_arr(data, ERR_TO_MANY_PARAM_C, c_arg);
	if (!are_digits(c_arg[1]) || !are_digits(c_arg[2]) || !are_digits(c_arg[3]))
		free_data_arr(data, "Incorrect color value: Only digits allowed", c_arg);
	if (ft_strlen(c_arg[1]) > 3 || ft_strlen(c_arg[2]) > 3 || ft_strlen(c_arg[3]) > 3)
		free_data_arr(data, ERR_OUT_OF_RANGE_C, c_arg);
	data->map.ceiling.r = ft_atoi(c_arg[1]);
	data->map.ceiling.g = ft_atoi(c_arg[2]);
	data->map.ceiling.b = ft_atoi(c_arg[3]);
	if (data->map.ceiling.r > 255 ||
		data->map.ceiling.g > 255 ||
		data->map.ceiling.b > 255)
	{
		free_data_arr(data, ERR_OUT_OF_RANGE_C, c_arg);
	}
	ft_free_array(c_arg);
}

void	floor_rgb(char *str, t_root *data)
{
	char	**f_arg;

	f_arg = splitbywhite(str, ',');
	if (f_arg == NULL)
		return ;
	if (!f_arg[1] || !f_arg[2] || !f_arg[3])
		free_data_arr(data, ERR_TO_FEW_PARAM_F, f_arg);
	if (f_arg[4] != NULL)
		free_data_arr(data, ERR_TO_MANY_PARAM_C, f_arg);
	if (!are_digits(f_arg[1]) || !are_digits(f_arg[2]) || !are_digits(f_arg[3]))
		free_data_arr(data, "Incorrect color value: Only digits allowed", f_arg);
	if (ft_strlen(f_arg[1]) > 3 || ft_strlen(f_arg[2]) > 3 || ft_strlen(f_arg[3]) > 3)
		free_data_arr(data, ERR_OUT_OF_RANGE_F, f_arg);
	data->map.floor.r = ft_atoi(f_arg[1]);
	data->map.floor.g = ft_atoi(f_arg[2]);
	data->map.floor.b = ft_atoi(f_arg[3]);
	if (data->map.floor.r > 255 ||
		data->map.floor.g > 255 ||
		data->map.floor.b > 255)
	{
		free_data_arr(data, ERR_OUT_OF_RANGE_F, f_arg);
	}
	ft_free_array(f_arg);
}

bool	is_full(t_map map)
{
	if (	is_c_full(map.ceiling) && is_f_full(map.floor) &&
			map.no_path != NULL && map.so_path != NULL &&
			map.ea_path != NULL && map.we_path != NULL)
			return (true);
	else
		return(false);
}
