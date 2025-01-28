/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/17 10:55:09 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/28 08:53:21 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_rgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	extract_rgb(mlx_texture_t *texture, int x, int y)
{
	return(texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel]);
}