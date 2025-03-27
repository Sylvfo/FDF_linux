/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:39:41 by sforster          #+#    #+#             */
/*   Updated: 2025/03/27 20:13:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_type(t_data *ima, int key) //fleches 
{	
	if (key == 65362) // haut
		ima->ymove += 20;
	if (key == 65364) //bas
		ima->ymove -= 20;
	if (key == 65363) //droite
		ima->xmove += 20;
	if (key == 65361) // gauche
		ima->xmove -= 20;
	if (key == 99) // centre
	{
		ima->xmove = 0;
		ima->ymove = 0;
	}
	return ;
}

void	ft_colors_type(t_data *ima, int key)
{
	ima->color = key - 30;
	return ;
}

void	ft_del_type(t_data *ima, int key)
{
	if (key == 122 && ima->del_y < ima->count_y)
		ima->del_y += 1;
	else if (key == 120 && ima->del_x < ima->count_x)
		ima->del_x += 1;
	return ;
}

int	ft_exit(t_data *ima)
{
	mlx_destroy_image(ima->mlx_ptr, ima->img);
	mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
	ft_printf("Window closed\n");
	ft_free_list(&ima->map);
	free(ima);
	exit(0);
	return (0);
}

void	ft_blue_green(t_data *ima)
{
	float	diff;
	int		color;
	t_map	*current;
	float	k;
	float	f;

	k = ima->count_z;
	f = (ft_max_z(ima->map) - ft_min_z(ima->map));
	diff = (ft_max_z(ima->map) - ft_min_z(ima->map)) / k;
	current = ima->map;
	while (current != NULL)
	{
		color = color_difference(0xFF, 0xFF00, f, (diff * current->z));
		current->color = color;
		current = current->nextx;
	}
	return ;
}
