/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 18:06:32 by mgross         #+#    #+#                */
/*   Updated: 2019/08/27 14:20:13 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_offset(t_fie *filler, t_pie *piece)
{
	int		x;
	int		ret;
	int		i;

	i = 0;
	x = 0;
	while (x < piece->piece_x)
	{
		ret = 0;
		ft_get_next_line(0, &filler->line);
		ret = ft_nchar(filler->line, '*');
		if (ret > 0)
		{
			i++;
			piece->lines_piece = piece->lines_piece + 1;
			if (ret < piece->first_star || piece->first_star == 0)
				piece->first_star = ret;
			ret = ft_strlen(filler->line);
			while (filler->line[ret - 1] != '*')
				ret--;
			if (ret > piece->last_star)
				piece->last_star = ret;
		}
		piece->temp_piece[x] = filler->line;
		x++;
	}
	piece->collums_piece = piece->last_star - piece->first_star + 1;
	// free(filler->line);
}

void		copy_piece(t_pie *piece, int x, int first_star, int i)
{
	int		y;
	int		temp;

	y = 0;
	temp = first_star;
	while (temp > piece->first_star)
	{
		piece->piece[x][y] = '.';
		y++;
		temp--;
	}
	while (first_star <= piece->last_star)
	{
		piece->piece[x][y] = piece->temp_piece[i][first_star - 1];
		y++;
		first_star++;
	}
	piece->piece[x][y] = '\0';
}

void		create_piece(t_pie *piece)
{
	int		x;
	int		i;
	int		first_star;

	i = 0;
	x = 0;
	while (x < piece->lines_piece)
	{
		first_star = ft_nchar(piece->temp_piece[i], '*');
		if (first_star != 0)
		{
			if (piece->first_line == -1)
				piece->first_line = i;
			piece->piece[x] = (char*)malloc(sizeof(piece->collums_piece + 1));
			if (piece->piece[x] == NULL)
				exit(-1); //<<<<<<< error management
			copy_piece(piece, x, first_star, i);
			x++;
		}
		i++;
	}
}

void		get_size_piece(t_fie *filler, t_pie *piece)
{
	ft_get_next_line(0, &filler->line);
	while (ft_isdigit(*filler->line) != 1)
		filler->line++;
	piece->piece_x = ft_atoi(&(*filler->line));
	while (ft_isdigit(*filler->line) == 1)
		filler->line++;
	filler->line++;
	piece->piece_y = ft_atoi(&(*filler->line));
}

void		update_piece(t_fie *filler, t_hmap *heatmap, t_pie *piece)
{
	int		i;

	i = 0;
	get_size_piece(filler, piece);
	if (ft_mem_array_alloc(&piece->temp_piece, piece->piece_x) == -1)
		error(filler, heatmap);
	get_offset(filler, piece);
	if (ft_mem_array_alloc(&piece->piece, piece->lines_piece) == -1)
		error(filler, heatmap);
	create_piece(piece);
}
