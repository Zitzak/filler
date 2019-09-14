/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_placement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:24:04 by mgross         #+#    #+#                */
/*   Updated: 2019/09/14 14:09:00 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** Test placement of piece to up and left
*/

int		get_sum_placement(t_hmap *heatmap, t_pie *piece, int x, int y, t_fie *filler)
{
	int		sum;
	int		temp_y;
	
	sum = 0; filler->nks = 0;//
	while (piece->x < piece->lines_piece)
	{	
		piece->y = 0;
		temp_y = y;
		while (piece->y < piece->collums_piece || temp_y == heatmap->size_y)
		{
			if (temp_y == heatmap->size_y || x == heatmap->size_x)
				return (0);
			if (heatmap->map[x][temp_y] == 0 && piece->piece[piece->x][piece->y] == '*')
				piece->star++;
			if (heatmap->map[x][temp_y] < -1 && piece->piece[piece->x][piece->y] == '*')
				return (0);
			sum = sum + heatmap->map[x][temp_y];
			piece->y++;
			temp_y++;
		}
		piece->x++;
		x++;
	}
	if (piece->star != 1)
		sum = 0;
	return (sum);
}

int		update_coord_placement(t_hmap *heatmap, int sum, int x, int y, int ret)
{
	if ((sum < heatmap->sum || heatmap->sum == 0))
	{
		if (ret == 0)
			ret = 1;
		heatmap->x = x;
		heatmap->sum = sum;
		heatmap->y = y;
	}
	return (ret);
}

int		check_placement(t_hmap *heatmap, t_pie *piece, t_fie *filler)
{
	int		x;
	int		y;
	int		sum;
	int		ret;

	ret = 0;
	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			piece->star = 0;
			piece->x = 0;
			sum = get_sum_placement(heatmap, piece, x, y, filler); // mag maar 4 variablen?
			if (sum > 0)
			{
				ret = update_coord_placement(heatmap, sum, x, y, ret);// mag maar 4 variablen?
			}
			y++;				
		}
		x++;
	}
	return (ret);
}
