/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:31:35 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:45:41 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static int			last_placement_enemy(t_fie *filler, t_hmap *heatmap)
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

void				update_enemy(t_fie *filler, t_hmap *heatmap)
{
	if (heatmap->enemy_num != 0)
	{
		if (!last_placement_enemy(filler, heatmap))
			heatmap->enemy_num = 0;
	}
}
