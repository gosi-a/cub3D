/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:21:28 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/16 11:06:10 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	comma_checker(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count == 2)
		return (true);
	return (false);
}

int	tex_paths_valid(char **split, t_root *data)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
	{
		if (data->map->no_path)
			free_data_arr(data, "NO: Is definied more then one time", split);
		return (data->map->no_path = split[1], 1);
	}
	else if (ft_strncmp(split[0], "SO", 3) == 0)
	{
		if (data->map->so_path)
			free_data_arr(data, "SO: Is definied more then one time", split);
		return (data->map->so_path = split[1], 1);
	}
	else if (ft_strncmp(split[0], "WE", 3) == 0)
	{
		if (data->map->we_path)
			free_data_arr(data, "WE: Is definied more then one time", split);
		return (data->map->we_path = split[1], 1);
	}
	else if (ft_strncmp(split[0], "EA", 3) == 0)
	{
		if (data->map->ea_path)
			free_data_arr(data, "EA: Is definied more then one time", split);
		return (data->map->ea_path = split[1], 1);
	}
	return (0);
}

int	ceiling_floor_valid(char **split_line, char *line, t_root *data)
{
	if (ft_strncmp(split_line[0], "C", 2) == 0)
	{
		ft_free_array(split_line);
		if (data->map->ceiling && !is_cf_full(data->map->ceiling, NULL))
		{
			ceiling_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "C: Is definied more then one time");
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0)
	{
		ft_free_array(split_line);
		if (data->map->floor && !is_cf_full(NULL, data->map->floor))
		{
			floor_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "F: Is definied more then one time");
	}
	return (0);
}

void	tex_validation(char *line, t_root *data)
{
	char	**split_line;

	split_line = splitbywhite(line, '\0');
	if (split_line [0] == NULL)
		return ;
	if (tex_paths_valid(split_line, data))
	{
		return ;
	}
	if (ceiling_floor_valid(split_line, line, data))
	{
		return ;
	}
	free_data_arr(data, ERR_GARBAGE_BEFORE_MAP, split_line);
}

void	if_valid_add(t_root *data)
{
	t_maplist	*curr;

	curr = data->map_list;
	while (curr != NULL && !is_full(data->map))
	{
		if (curr->line[0] != '\n')
		{
			tex_validation(curr->line, data);
		}
		curr = curr->next;
	}
	data->map_search = curr;
	// printf("%s\n",data->map->no_path);
	// printf("%s\n",data->map->so_path);
	// printf("%s\n",data->map->ea_path);
	// printf("%s\n",data->map->we_path);
	// printf("ceiling value r: %d\n",data->map->ceiling->r);
	// printf("ceiling value g: %d\n",data->map->ceiling->g);
	// printf("ceiling value b: %d\n",data->map->ceiling->b);
	// printf("floor value r: %d\n",data->map->floor->r);
	// printf("floor value g: %d\n",data->map->floor->g);
	// printf("floor value b: %d\n",data->map->floor->b);
}
