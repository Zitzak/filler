/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:31:35 by mgross         #+#    #+#                */
/*   Updated: 2019/09/16 18:14:53 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		last_placement_enemy(t_fie *filler, t_hmap *heatmap)
{
	int		x;
	int		y;
	int		n;

	x = 0;
	n = 0;
	heatmap->enemy_num--;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->enemy && heatmap->map[x][y] >= 0)
			{
				heatmap->map[x][y] = heatmap->enemy_num;
				n++;
			}
			y++;
		}
		x++;
	}
	return (n);
}

void		get_direction_down(t_hmap *heatmap, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (heatmap->map[x][y] == (heatmap->enemy_num + 1) && strategy->enemy_last_x == -1)
			{
				update_enemy_last(strategy, x, y);
				// strategy->enemy_last_x = x + 1;
				// strategy->enemy_last_y = y + 1;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && strategy->enemy_curr_x == -1)
			{
				update_enemy_curr(strategy, x, y);
				// strategy->enemy_curr_x = x + 1;
				// strategy->enemy_curr_y = y + 1;
			}
			y++;
		}
		x++;
		if (strategy->enemy_last_x != -1 && strategy->enemy_curr_x != -1)
			return ;
	}
}

void		get_direction_up(t_hmap *heatmap, t_str *strategy)
{
	int		x;
	int		y;

	x = heatmap->size_x - 1;
	while (x >= 0)
	{
		y = heatmap->size_y - 1;
		while (y >= 0)
		{
			if (heatmap->map[x][y] == (heatmap->enemy_num + 1) && strategy->enemy_last_x == -1)
			{
				update_enemy_last(strategy, x, y);
				// strategy->enemy_last_x = x + 1;
				// strategy->enemy_last_y = y + 1;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && strategy->enemy_curr_x == -1)
			{
				update_enemy_curr(strategy, x, y);
				// strategy->enemy_curr_x = x + 1;
				// strategy->enemy_curr_y = y + 1;
			}
			y--;
		}
		x--;
		if (strategy->enemy_last_x != -1 && strategy->enemy_curr_x != -1)
			return ;
	}
}

void		update_direction(t_str *strategy)
{
	int		x;
	int		y;

	if (strategy->enemy_last_x != -1)
	{
		x = strategy->enemy_last_x - strategy->enemy_curr_x;
		y = strategy->enemy_last_y - strategy->enemy_curr_y;
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
	strategy->nks = 5;
	if (heatmap->enemy_num != 0)
	{
		if (!last_placement_enemy(filler, heatmap))
			heatmap->enemy_num = 0;
	}
	if (filler->start == 1)
	{
		get_direction_down(heatmap, strategy);
	}
	if (filler->start == 0)
	{
		get_direction_up(heatmap, strategy);
	}
	update_direction(strategy);
}
