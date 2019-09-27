/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_heatmap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:21:55 by mgross         #+#    #+#                */
/*   Updated: 2019/09/27 10:31:55 by Marvin        ########   odam.nl         */
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

void		replace_pieces_of_self(t_fie *filler, t_hmap *heatmap)
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

void		update_heatmap(t_fie *filler, t_hmap *heatmap, t_str *strategy)
{
	heatmap_to_zero(heatmap);
	if (strategy->map == 'd')
		heatmap_from_down(heatmap);
	else if (strategy->map == 'u')
		heatmap_from_up(heatmap);
	else if (strategy->map == 'l')
		heatmap_from_left(heatmap);
	else if (strategy->map == 'r')
		heatmap_from_right(heatmap);
	else
		heatmap_to_enemy(heatmap);
	replace_pieces_of_self(filler, heatmap);
}
