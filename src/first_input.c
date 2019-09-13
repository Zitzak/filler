/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 11:56:37 by mgross         #+#    #+#                */
/*   Updated: 2019/09/13 16:22:46 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		create_field(t_fie *filler, t_hmap *heatmap)
{
	int		x;

	x = 0;
	ft_get_next_line(0, &filler->line);
	while (ft_isdigit(*filler->line) != 1)
		filler->line++;
	filler->field_x = ft_atoi(&(*filler->line));
	heatmap->size_x = filler->field_x;
	while (ft_isdigit(*filler->line) == 1)
		filler->line++;
	filler->line++;
	filler->field_y = ft_atoi(&(*filler->line));
	heatmap->size_y = filler->field_y;
	filler->field = (char**)ft_mem_array_alloc(filler->field_x,
	sizeof(char*) * filler->field_x, sizeof(char) * (filler->field_y + 1));
	if (filler->field == NULL)
		return (-1);
	return (0);
}

int		create_heatmap(t_hmap *heatmap)
{
	int		x;

	x = 0;
	heatmap->map = (int**)ft_mem_array_alloc(heatmap->size_x,
	(sizeof(int*) * heatmap->size_x), (sizeof(int) * heatmap->size_y));
	if (heatmap->map == NULL)
	{
		return (-1);
	}
	return (0);
}

void		get_token(t_fie *filler)
{
	ft_get_next_line(0, &filler->line);
	filler->line = ft_strstr((const char*)filler->line, (const char*)"p1");
	if (filler->line == NULL)
	{
		filler->me = 'X';
		filler->enemy = 'O';
	}
	else
	{
		filler->me = 'O';
		filler->enemy = 'X';
	}
}

void		init_var_first_input(t_fie *filler, t_hmap *heatmap, t_str *strategy)
{
	filler->start = -1;
	heatmap->enemy_num = -1;
	if (filler->field_x == 15)
		strategy->size_field = 's';
	else if (filler->field_x == 24)
		strategy->size_field = 'm';
	else
		strategy->size_field = 'l';
		strategy->down = 0;
	strategy->up = 0;
	strategy->left = 0;
	strategy->right = 0;
	strategy->ul_corner = 0;
	strategy->ur_corner = 0;
	strategy->dl_corner = 0;
	strategy->dr_corner = 0;
}

int			first_input(t_fie *filler, t_hmap *heatmap, t_str *strategy)
{
	get_token(filler);
	if (create_field(filler, heatmap) == -1)
		return (-1);
	if (create_heatmap(heatmap) == -1)
		return(-1);
	init_var_first_input(filler, heatmap, strategy);
	return (0);
}
