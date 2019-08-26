/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:31:35 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 21:37:48 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		last_placement_enemy(t_fie *filler, t_hmap *heatmap)
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
			if (filler->field[x][y] == filler->enemy && heatmap->map[x][y] > -1)
				heatmap->map[x][y] = heatmap->enemy_num;
			y++;
		}
		x++;
	}
}

void		get_direction(t_hmap *heatmap, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] == (heatmap->enemy_num + 1) && strategy->last_piece_x == -1)
			{
				strategy->last_piece_x = x;
				strategy->last_piece_y = y;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && strategy->current_piece_x == -1)
			{
				strategy->current_piece_x = x;
				strategy->current_piece_y = y;
			}
			y++;
		}
		x++;
		if (strategy->last_piece_x != -1 && strategy->current_piece_x != -1)
			return ;
	}
}

void		update_direction(t_str *strategy)
{
	int		x;
	int		y;

	if (strategy->last_piece_x != -1)
	{
		x = strategy->current_piece_x - strategy->last_piece_x;
		y = strategy->current_piece_y - strategy->last_piece_y;
		if (x < 0 && y == 0)
			strategy->down++;
		else if (x < 0 && y < 0)
			strategy->dr_corner++;
		else if (x < 0 && y > 0)
			strategy->dl_corner++;
		else if (x > 0 && y == 0)
			strategy->up++;
		else if (x > 0 && y < 0)
			strategy->ur_corner++;
		else if (x > 0 && y > 0)
			strategy->ul_corner++;		
		else if (x == 0 && y < 0)
			strategy->right++;
		else
			strategy->left++;
	}
}

void		update_enemy(t_fie *filler, t_hmap *heatmap, t_str *strategy)
{
	last_placement_enemy(filler, heatmap);
	get_direction(heatmap, strategy);
	update_direction(strategy);
}
