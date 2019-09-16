/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pos2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:49:58 by mgross         #+#    #+#                */
/*   Updated: 2019/09/16 15:18:31 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		init_var_get_pos(t_str *strategy)
{
	strategy->enemy_furthest_y = -1;
	strategy->enemy_furthest_x = -1;
	strategy->my_furthest_x = -1;
	strategy->my_furthest_y = -1;
}

void		assign_pos_enemy_x(t_str *strategy, int x, int y)
{
	strategy->enemy_furthest_x = x + 1;
	strategy->enemy_furthest_xy = y + 1;
}

void		assign_pos_enemy_y(t_str *strategy, int x, int y)
{
	strategy->enemy_furthest_y = y + 1;
	strategy->enemy_furthest_yx = x + 1;
}

void		assign_pos_me_x(t_str *strategy, int x, int y)
{
	strategy->my_furthest_x = x + 1;
	strategy->my_furthest_xy = y + 1;
}

void		assign_pos_me_y(t_str *strategy, int x, int y)
{
	strategy->my_furthest_y = y + 1;
	strategy->my_furthest_yx = x + 1;
}
