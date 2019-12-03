/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_heatmap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:21:55 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:47:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void		heatmap_to_zero(t_hmap *heatmap)
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

static void		replace_pieces_of_self(t_fie *filler, t_hmap *heatmap)
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

void			update_heatmap(t_fie *filler, t_hmap *heatmap)
{
	heatmap_to_zero(heatmap);
	heatmap_to_enemy(heatmap);
	replace_pieces_of_self(filler, heatmap);
}
