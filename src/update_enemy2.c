/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_enemy2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:48:20 by mgross         #+#    #+#                */
/*   Updated: 2019/09/16 16:50:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		update_enemy_curr(t_str *strategy, int x, int y)
{
	strategy->enemy_curr_x = x + 1;
	strategy->enemy_curr_y = y + 1;
}

void		update_enemy_last(t_str *strategy, int x, int y)
{
	strategy->enemy_last_x = x + 1;
	strategy->enemy_last_y = y + 1;
}
