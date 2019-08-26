/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:01 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 21:11:40 by Marvin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdio.h>//
#include <stdlib.h>
#include <fcntl.h>//
#include "../libft/includes/libft.h"

#define BUFF_SIZE_FILLER 1024

/*
** This is the heatmap(hmap) structure.
*/

typedef	struct 	s_hmap
{
	int		**map;
	int		size_x;
	int		size_y;
	int		enemy_num;
}				t_hmap;

/*
**This is the piece(pie) structure
*/

typedef struct	s_pie
{
	int		piece_x;
	int		piece_y;
	int		last_star;
	int		first_star;
	int		lines_piece;
	int		collums_piece;
	char	**piece;
	char	**temp_piece;
}				t_pie;

/*
** This is the strategy(str) structure.
*/

typedef struct	s_str
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		ur_corner;
	int		ul_corner;
	int		dr_corner;
	int		dl_corner;
	int		last_piece_x;
	int		last_piece_y;
	int		current_piece_x;
	int		current_piece_y;
}				t_str;

/*
** This is the field(fie) structure.
*/

typedef struct s_fie
{
	char	me;
	int 	fd;// < -------------------
	char	enemy;
	short	start;
	// int		last_star;
	// int		first_star;
	// int		lines_piece;
	// int		collums_piece;
	int		field_x;
	int		field_y;
	char	**field;
	// int		piece_x;
	// int		piece_y;
	// char	**piece;
	// char	**temp_piece;
	char	*line;
}				t_fie;

void	print_test(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece);// <---------------
void	first_input(t_fie *filler, t_hmap *heatmap);
void	get_token(t_fie *filler);
void	update_field(t_fie *filler);
int		create_field(t_fie *filler, t_hmap *heatmap);
void	get_size_piece(t_pie *piece);
void	get_offset(t_fie *filler, t_pie *piece);
void	update_game(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece);
void	update_piece(t_fie *filler, t_hmap *heatmap, t_pie *piece);
void	create_piece(t_pie *piece);
void	init_var_update(t_str *strategy, t_pie *piece);
void	copy_piece(t_pie *piece, int x, int first_star, int i);
void	error(t_fie *filler, t_hmap *heatmap);
void	main_control(t_fie *filler, t_hmap *heatmap);
void	find_first_piece(t_fie *filler);
int		create_heatmap(t_hmap *heatmap);
void	update_heatmap(t_fie *filler, t_hmap *heatmap);
void	update_placement_enemy(t_fie *filler, t_hmap *heatmap);
void	update_map(t_fie *filler, t_hmap *heatmap);
void	get_direction(t_hmap *heatmap, t_str *strategy);
void	update_enemy(t_fie *filler, t_hmap *heatmap, t_str *strategy);
void	heatmap_to_zero(t_hmap *heatmap);
void	heatmap_from_down(t_hmap *heatmap);
void	heatmap_from_up(t_hmap *heatmap);
void	heatmap_from_right(t_hmap *heatmap);
void	heatmap_from_left(t_hmap *heatmap);
int		redirect_heatmap_to_enemy(t_hmap *heatmap, int n);
void	heatmap_to_enemy(t_hmap *heatmap);
void	replace_pieces_of_self(t_fie *filler, t_hmap *heatmap);
void	update_direction(t_str *strategy);
void	init_var_first_input(t_fie *filler, t_hmap *heatmap);
// void	update_strategy(t_fie *filler, t_str *strategy);

#endif