/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 13:31:35 by mgross         #+#    #+#                */
/*   Updated: 2019/09/09 16:23:24 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		last_placement_enemy(t_fie *filler, t_hmap *heatmap)
{
	int		x;
	int		y;

	x = 0;
	// write(filler->fd, "k:", 2);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	heatmap->enemy_num--;
	while (x < filler->field_x)
	{
		y = 0;
		write(filler->fd, "n3b1:", 5);
		while (y < filler->field_y)
		{
			write(filler->fd, "n3b2:", 5);
			write(filler->fd, "k:", 2);ft_putnbr_fd(heatmap->map[0][0], filler->fd);
			write(filler->fd, "k1:", 2);ft_putnbr_fd(filler->field[0][0], filler->fd);
			if (filler->field[x][y] == filler->enemy && heatmap->map[x][y] >= 0)
				heatmap->map[x][y] = heatmap->enemy_num;
			y++;
		}
		x++;
	}
}

void		get_direction_down(t_hmap *heatmap, t_str *strategy, t_fie *filler)
{
	int		x;
	int		y;

	x = 0;
	filler->nks = 5;//
	// write(filler->fd, "n:\n", 3);ft_putnbr_fd(heatmap->map[0][0], filler->fd);write(filler->fd, "\n", 1);
	while (x < heatmap->size_x)
	{
		y = 0;
		// write(filler->fd, "test7\n", 6);
		while (y < heatmap->size_y)
		{
			// write(filler->fd, "test8a\n", 7);ft_putnbr_fd(y, filler->fd);write(filler->fd, "\n", 1);ft_putnbr_fd(heatmap->enemy_num, filler->fd);write(filler->fd, "\n", 1);ft_putnbr_fd(strategy->enemy_last_x, filler->fd);write(filler->fd, "\n", 1);
			if (heatmap->map[x][y] == (heatmap->enemy_num + 1) && strategy->enemy_last_x == -1)
			{
				// write(filler->fd, "test8\n", 6);
				strategy->enemy_last_x = x;
				strategy->enemy_last_y = y;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && strategy->enemy_curr_x == -1)
			{
				// write(filler->fd, "test9\n", 6);
				strategy->enemy_curr_x = x;
				strategy->enemy_curr_y = y;
			}
			// write(filler->fd, "test10\n", 7);
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
				strategy->enemy_last_x = x;
				strategy->enemy_last_y = y;
			}
			if (heatmap->map[x][y] == (heatmap->enemy_num) && strategy->enemy_curr_x == -1)
			{
				strategy->enemy_curr_x = x;
				strategy->enemy_curr_y = y;
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
		x = strategy->enemy_curr_x - strategy->enemy_last_x;
		y = strategy->enemy_curr_y - strategy->enemy_last_y;
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
	// write(filler->fd, "test3\n", 6);
	last_placement_enemy(filler, heatmap);
	// strategy->left = 5;
	// write(filler->fd, "test4\n", 6);
	// if (filler->start == 1)
	// {
		// write(filler->fd, "test5a\n", 7);
		// get_direction_down(heatmap, strategy, filler);
	// }
	// write(filler->fd, "test5\n", 6);
	// if (filler->start == 0)
	// 	get_direction_up(heatmap, strategy);
	// write(filler->fd, "test6\n", 6);
	// update_direction(strategy);
	// write(filler->fd, "test7\n", 6);
}
