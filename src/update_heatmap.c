/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_heatmap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:21:55 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 17:03:36 by Marvin        ########   odam.nl         */
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

void		replace_pieces_of_self(t_info *filler, t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->me)
				heatmap->map[x][y] = 0;
			y++;
		}
		x++;
	}
}

void		update_heatmap(t_info *filler, t_hmap *heatmap)
{
	heatmap_to_zero(heatmap);
	//choose how to fill in heatmap depending on strategy
	// heatmap_from_down(heatmap);
	heatmap_to_enemy(heatmap);
	replace_pieces_of_self(filler, heatmap);
}