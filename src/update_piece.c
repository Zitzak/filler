/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 18:06:32 by mgross         #+#    #+#                */
/*   Updated: 2019/08/22 15:17:12 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_offset(t_info *filler)
{
	int		x;
	int		ret;

	x = 0;
	while (x < filler->piece_x)
	{
		ft_get_next_line(0, &filler->line);
		ret = ft_nchar(filler->line, '*');
		if (ret > 0)
		{
			filler->lines_piece++;
			if (ret < filler->first_star || filler->first_star == 0)
				filler->first_star = ret;
			ret = ft_strlen(filler->line);
			while (filler->line[ret - 1] != '*')
				ret--;
			if (ret > filler->last_star)
				filler->last_star = ret;
		}
		filler->temp_piece[x] = filler->line;
		x++;
	}
	filler->temp_piece[x] = NULL;
	filler->collums_piece = filler->last_star - filler->first_star + 1;
}

void		copy_piece(t_info *filler, int x, int first_star, int i)
{
	int		y;
	int		temp;

	y = 0;
	temp = first_star;
	while (temp > filler->first_star)
	{
		filler->piece[x][y] = '.';
		y++;
		temp--;
	}
	while (first_star <= filler->last_star)
	{
		filler->piece[x][y] = filler->temp_piece[i][first_star - 1];
		y++;
		first_star++;
	}
	filler->piece[x][y] = '\0';
}

void		create_piece(t_info *filler)
{
	int		x;
	int		i;
	int		first_star;

	i = 0;
	x = 0;
	while (x < filler->lines_piece)
	{
		first_star = ft_nchar(filler->temp_piece[i], '*');
		if (first_star != 0)
		{
			filler->piece[x] = (char*)ft_memalloc(filler->collums_piece + 1);
			copy_piece(filler, x, first_star, i);
			x++;
		}
		i++;
	}
	filler->piece[x] = NULL;
}

void		get_size_piece(t_info *filler)
{
	ft_get_next_line(0, &filler->line);
	while (ft_isdigit(*filler->line) != 1)
		filler->line++;
	filler->piece_x = ft_atoi(&(*filler->line));
	while (ft_isdigit(*filler->line) == 1)
		filler->line++;
	filler->line++;
	filler->piece_y = ft_atoi(&(*filler->line));
}

void		update_piece(t_info *filler, t_hmap *heatmap)
{
	get_size_piece(filler);
	if (ft_mem_array_alloc(&filler->temp_piece, filler->piece_x) == -1)
		error(filler, heatmap);
	get_offset(filler);
	if (ft_mem_array_alloc(&filler->piece, filler->lines_piece) == -1)
		error(filler, heatmap);
	create_piece(filler);
}
