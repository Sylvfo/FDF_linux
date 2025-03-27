/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:38:31 by sforster          #+#    #+#             */
/*   Updated: 2025/03/27 20:13:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso_30(t_map *carte)
{
	t_map	*current;
	float	a;
//	float	pi;

//	pi = (float)(M_PI);
	current = carte;
	a = 30 * (M_PI / 180);
	while (current != NULL)
	{
		current->xiso = ((current->x - current->y) * cos(a));
		current->yiso = ((current->x + current->y)
				* sin(a) - current->z);
		current = current->nextx;
	}
	ft_printf("Projection iso 30\n");
}

void	ft_iso_45(t_map *carte)
{
	t_map	*current;
	float	a;
//	float	pi;

//	pi = (float)(M_PI);
	current = carte;
	a = 45 * (M_PI / 180);
	while (current != NULL)
	{
		current->xiso = ((current->x - current->y) * cos(a));
		current->yiso = ((current->x + current->y)
				* sin(a) - current->z);
		current = current->nextx;
	}
	ft_printf("Projection iso 45\n");
}
