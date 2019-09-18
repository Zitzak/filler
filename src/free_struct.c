/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 18:13:46 by mgross         #+#    #+#                */
/*   Updated: 2019/09/18 21:26:25 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	free_filler(t_fie *filler)
{
	ft_strarrdel(&filler->field, (size_t)filler->field_x);
}

void	free_piece(t_pie *piece)
{
	ft_strarrdel(&piece->temp_piece, (size_t)piece->piece_x);
	ft_strarrdel(&piece->piece, (size_t)piece->lines_piece);
}

void	free_heatmap(t_hmap *heatmap)
{
	int		x;

	x = 0;
	while (x < heatmap->size_x)
	{
		ft_memdel((void*)&heatmap->map[x]);
		x++;
	}
	heatmap->map = NULL;
}

void	free_redirect(t_fie **filler, t_hmap **heatmap, t_pie **piece,
		t_str **strategy)
{
	if (*filler != NULL)
	{
		free_filler(*filler);
		free(*filler);
	}
	*filler = NULL;
	if (*heatmap != NULL)
	{
		free_heatmap(*heatmap);
		free(*heatmap);
	}
	*heatmap = NULL;
	if (*piece != NULL)
	{
		if ((*piece)->piece != NULL)
			free_piece(*piece);
		free(*piece);
	}
	*piece = NULL;
	if (*strategy != NULL)
		free(*strategy);
	*strategy = NULL;
}
