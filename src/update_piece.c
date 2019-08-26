/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 18:06:32 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 21:20:53 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		get_offset(t_fie *filler, t_pie *piece)
{
	int		x;
	int		ret;

	x = 0;
	while (x < piece->piece_x)
	{
		ft_get_next_line(0, &filler->line);
		ret = ft_nchar(filler->line, '*');
		if (ret > 0)
		{
			piece->lines_piece++;
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
			piece->piece[x] = (char*)ft_memalloc(piece->collums_piece + 1);
			copy_piece(piece, x, first_star, i);
			x++;
		}
		i++;
	}
	piece->piece[x] = NULL;
}

void		get_size_piece(t_pie *piece)
{
	char		*line;

	ft_get_next_line(0, &line);
	while (ft_isdigit(*line) != 1)
		line++;
	piece->piece_x = ft_atoi(&(*line));
	while (ft_isdigit(*line) == 1)
		line++;
	line++;
	piece->piece_y = ft_atoi(&(*line));
	// free(line);
}

void		update_piece(t_fie *filler, t_hmap *heatmap, t_pie *piece)
{
	get_size_piece(piece);
	if (ft_mem_array_alloc(&piece->temp_piece, piece->piece_x) == -1)
		error(filler, heatmap);
	get_offset(filler, piece);
	if (ft_mem_array_alloc(&piece->piece, piece->lines_piece) == -1)
		error(filler, heatmap);
	create_piece(piece);
}
