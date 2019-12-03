/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_heatmap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 13:21:23 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:46:39 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void			change_heatmap(t_hmap *heatmap, int n, int x, int y)
{
	if (x != 0 && y != 0)
		if (heatmap->map[x - 1][y - 1] == 0)
			heatmap->map[x - 1][y - 1] = n;
	if (y != 0)
		if (heatmap->map[x][y - 1] == 0)
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

static int			redirect_heatmap_to_enemy(t_hmap *heatmap, int n)
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
			if ((heatmap->map[x][y] < -1) || (heatmap->map[x][y] ==
			(n - 1) && n != 1))
			{
				change_heatmap(heatmap, n, x, y);
			}
			y++;
		}
		x++;
	}
	return (ret);
}

void				heatmap_to_enemy(t_hmap *heatmap)
{
	int		n;

	n = 1;
	while (redirect_heatmap_to_enemy(heatmap, n))
	{
		n++;
	}
}
