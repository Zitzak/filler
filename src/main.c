/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:57 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:45:29 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static int			init_struct(t_fie **filler, t_hmap **heatmap, t_pie **piece)
{
	*filler = (t_fie*)ft_memalloc(sizeof(t_fie));
	if (filler == NULL)
		return (-1);
	*heatmap = (t_hmap*)ft_memalloc(sizeof(t_hmap));
	if (heatmap == NULL)
		return (-1);
	*piece = (t_pie*)ft_memalloc(sizeof(t_pie));
	if (piece == NULL)
		return (-1);
	return (0);
}

int					main(void)
{
	t_fie			*filler;
	t_hmap			*heatmap;
	t_pie			*piece;

	if (init_struct(&filler, &heatmap, &piece) == -1)
		return (-1);
	if (first_input(filler, heatmap) == -1)
		return (-1);
	if (main_control(filler, heatmap, piece) == -1)
		return (-1);
	return (0);
}
