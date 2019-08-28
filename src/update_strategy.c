/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_strategy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 18:59:07 by Marvin         #+#    #+#                */
/*   Updated: 2019/08/27 17:22:05 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		change_strategy(t_str *strategy)
{
	strategy->map = 'g';
}

void		update_strategy(t_fie *filler, t_str *strategy)
{
	get_furthest_pos(filler, strategy);
	change_strategy(strategy);
}