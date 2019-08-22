/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_heatmap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:21:55 by mgross         #+#    #+#                */
/*   Updated: 2019/08/22 16:16:48 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		heatmap_to_zero(t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] > 0)
			{
				heatmap->map[x][y] = 0;
			}
			y++;
		}
		x++;
	}
}

void		update_heatmap(t_hmap *heatmap)
{
	heatmap_to_zero(heatmap);
	heatmap_from_down(heatmap);
}