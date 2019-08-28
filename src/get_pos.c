/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pos.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:43:24 by mgross         #+#    #+#                */
/*   Updated: 2019/08/27 17:21:26 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_my_pos_down(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	strategy->my_furthest_x = -1;
	strategy->my_furthest_y = -1;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->me)
			{
				if (x > strategy->my_furthest_x)
					strategy->my_furthest_x = x + 1;
				if (y > strategy->my_furthest_y)
					strategy->my_furthest_y = y + 1;
			}
			y++;
		}
		x++;
	}
}

void		get_my_pos_up(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	strategy->my_furthest_x = filler->field_x;
	strategy->my_furthest_y = filler->field_y;
	x = filler->field_x - 1;
	while (x >= 0)
	{
		y = filler->field_y - 1;
		while (y >= 0)
		{
			if (filler->field[x][y] == filler->me)
			{
				if (x < strategy->my_furthest_x)
					strategy->my_furthest_x = x + 1;
				if (y < strategy->my_furthest_y)
					strategy->my_furthest_y = y + 1;
			}
			y--;
		}
		x--;
	}
}

void		get_enemy_pos_down(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	x = 0;
	strategy->enemy_furthest_x = -1;
	strategy->enemy_furthest_y = -1;
	while (x < filler->field_x)
	{
		y = 0;
		while (y < filler->field_y)
		{
			if (filler->field[x][y] == filler->enemy)
			{
				if (x > strategy->enemy_furthest_x)
					strategy->enemy_furthest_x = x + 1;
				if (y > strategy->enemy_furthest_y)
					strategy->enemy_furthest_y = y + 1;
			}
			y++;
		}
		x++;
	}
}

void		get_enemy_pos_up(t_fie *filler, t_str *strategy)
{
	int		x;
	int		y;

	strategy->enemy_furthest_x = filler->field_x;
	strategy->enemy_furthest_y = filler->field_y;
	x = filler->field_x - 1;
	while (x >= 0)
	{
		y = filler->field_y - 1;
		while (y >= 0)
		{
			if (filler->field[x][y] == filler->enemy)
			{
				if (x < strategy->enemy_furthest_x)
					strategy->enemy_furthest_x = x + 1;
				if (y < strategy->enemy_furthest_y)
					strategy->enemy_furthest_y = y + 1;
			}
			y--;
		}
		x--;
	}
}

void		get_furthest_pos(t_fie *filler, t_str *strategy)
{
	if (filler->start == 0)
	{
		get_my_pos_down(filler, strategy);
		get_enemy_pos_up(filler, strategy);
	}
	if (filler->start == 1)
	{
		get_my_pos_up(filler,strategy);
		get_enemy_pos_down(filler, strategy);
	}
}
