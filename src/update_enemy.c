/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:31:35 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 16:17:08 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		last_placement_enemy(t_info *filler, t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	heatmap->enemy_num--;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->other && heatmap->map[x][y] > -1)
				heatmap->map[x][y] = heatmap->enemy_num;
			y++;
		}
		x++;
	}
}

void		get_direction(t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] == (heatmap->enemy_num + 1) && heatmap->last_piece_x == -1)
			{
				heatmap->last_piece_x = x;
				heatmap->last_piece_y = y;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && heatmap->current_piece_x == -1)
			{
				heatmap->current_piece_x = x;
				heatmap->current_piece_y = y;
			}
			y++;
		}
		x++;
		if (heatmap->last_piece_x != -1 && heatmap->current_piece_x != -1)
			return ;
	}
}

// void		update_strategy(t_hmap *heatmap)
// {

// }

void		update_enemy(t_info *filler, t_hmap *heatmap)
{
	last_placement_enemy(filler, heatmap);
	get_direction(heatmap);
	// update_strategy(heatmap);
}