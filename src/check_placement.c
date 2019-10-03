/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_placement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:24:04 by mgross         #+#    #+#                */
/*   Updated: 2019/10/02 15:05:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		get_sum_redirect(t_hmap *heatmap, t_pie *piece, int x, int temp_y)
{
	if ((temp_y == heatmap->size_y || x == heatmap->size_x) ||
	(heatmap->map[x][temp_y] < -1 && piece->piece[piece->x][piece->y] == '*'))
		return (0);
	if (heatmap->map[x][temp_y] == 0 && piece->piece[piece->x][piece->y] == '*')
		piece->star++;
	return (1);
}

int		get_sum_placement(t_hmap *heatmap, t_pie *piece, int x, int y)
{
	int		sum;
	int		temp_y;

	sum = 0;
	while (piece->x < piece->lines_piece)
	{
		piece->y = 0;
		temp_y = y;
		while (piece->y < piece->collums_piece || temp_y == heatmap->size_y)
		{
			if (!get_sum_redirect(heatmap, piece, x, temp_y))
				return (0);
			if (piece->piece[piece->x][piece->y] != '.')
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

void	update_coord_placement(t_hmap *heatmap, int sum, int x, int y)
{
	if ((sum <= heatmap->sum || heatmap->sum == 0))
	{
		if (sum < heatmap->sum || heatmap->sum == 0 || (sum == heatmap->sum
			&& (heatmap->start & START_TOP) == START_TOP))
		{
			heatmap->x = x;
			heatmap->sum = sum;
			heatmap->y = y;
		}
	}
}

int		check_placement(t_hmap *heatmap, t_pie *piece)
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
			sum = get_sum_placement(heatmap, piece, x, y);
			if (sum > 0)
			{
				ret = 1;
				update_coord_placement(heatmap, sum, x, y);
			}
			y++;
		}
		x++;
	}
	return (ret);
}
