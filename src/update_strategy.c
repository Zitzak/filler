/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_strategy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Marvin <Marvin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 18:59:07 by Marvin         #+#    #+#                */
/*   Updated: 2019/09/10 13:47:27 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		change_strategy(t_str *strategy)
{
	strategy->map = 'u';
}

void		update_strategy(t_fie *filler, t_str *strategy)
{
	filler->nks = 5;//
	// get_furthest_pos(filler, strategy);
	change_strategy(strategy);
}