/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_heatmap2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 15:43:16 by Marvin         #+#    #+#                */
/*   Updated: 2019/08/26 16:55:13 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		change_heatmap(t_hmap *heatmap, int n, int x, int y)
{
	if (x != 0 && y != 0)
		if (heatmap->map[x - 1][y - 1] == 0)
			heatmap->map[x - 1][y - 1] = n;
	if (y != 0)
		if (heatmap->map[x][y - 1] == 0 && y != 0)
			heatmap->map[x][y - 1] = n;
	if (x != (heatmap->size_x - 1) && y != 0)
		if (heatmap->map[x + 1][y - 1] == 0)
			heatmap->map[x + 1][y - 1] = n;
	if (x != (heatmap->size_x - 1))
		if (heatmap->map[x + 1][y] == 0)
			heatmap->map[x + 1][y] = n;
	if (x != (heatmap->size_x - 1) && y != (heatmap->size_y - 1))
		if (heatmap->map[x + 1][y + 1] == 0)
			heatmap->map[x + 1][y + 1] = n;
	if (y != (heatmap->size_y - 1))
		if (heatmap->map[x][y + 1] == 0)
			heatmap->map[x][y + 1] = n;
	if (x != 0 && y != (heatmap->size_y - 1))
		if (heatmap->map[x - 1][y + 1] == 0)
			heatmap->map[x - 1][y + 1] = n;
	if (x != 0)
		if (heatmap->map[x - 1][y] == 0)
			heatmap->map[x - 1][y] = n;
}

int			direct_change_heatmap(t_hmap *heatmap, int n)
{
	int		x;
	int		y;
	int		ret;

	ret = 0;
	x = 0;
	while (x < heatmap->size_x)
	{
		y = 0;
		while (y < heatmap->size_y)
		{
			if (ret == 0 && heatmap->map[x][y] == 0)
				ret = 1;
			if ((heatmap->map[x][y] < 0) || (heatmap->map[x][y] == (n -1) && (n - 1) != 0))
			{
				change_heatmap(heatmap, n, x, y);
			}
			y++;
		}
		x++;
	}
	return (ret);
}
