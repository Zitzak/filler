/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 12:05:21 by mgross         #+#    #+#                */
/*   Updated: 2019/10/08 20:45:59 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void		find_first_piece(t_fie *filler, t_hmap *heatmap)
{
	int		i;

	i = 0;
	heatmap->start = 0;
	while (filler->line[i] != '\0')
	{
		if (filler->line[i] == 'X' || filler->line[i] == 'O')
		{
			if (filler->line[i] == filler->me)
			{
				filler->start |= START_TOP;
			}
			else
			{
				filler->start |= START_BOTT;
			}
			break ;
		}
		i++;
	}
	heatmap->start = filler->start;
}

int				update_field(t_fie *filler, t_hmap *heatmap)
{
	int		x;

	x = 0;
	if (ft_get_next_line(0, &filler->line) == 0)
		return (0);
	if (*filler->line != ' ')
	{
		free_line(filler);
		ft_get_next_line(0, &filler->line);
	}
	free_line(filler);
	while (x < filler->field_x)
	{
		ft_get_next_line(0, &filler->line);
		if ((filler->start & START_BOTT) != START_BOTT &&
		(filler->start & START_TOP) != START_TOP)
			find_first_piece(filler, heatmap);
		filler->field[x] = ft_strcpy(filler->field[x], (filler->line + 4));
		free_line(filler);
		x++;
	}
	return (1);
}
