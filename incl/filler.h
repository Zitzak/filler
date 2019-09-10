/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:01 by mgross         #+#    #+#                */
/*   Updated: 2019/09/10 13:38:08 by Marvin        ########   odam.nl         */
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
	int		sum;
	int		x;
	int		y;
}				t_hmap;

/*
**This is the piece(pie) structure
*/

typedef struct	s_pie
{
	int		star;
	int		x;
	int		y;
	int		piece_x;
	int		piece_y;
	int		last_star;
	int		first_star;
	int		first_line;
	int		lines_piece;
	int		collums_piece;
	char	**piece;
	char	**temp_piece;
	int		nks;
}				t_pie;

/*
** This is the strategy(str) structure.
*/

typedef struct	s_str
{
	char	size_field;
	char	map;
	int		up;
	int		down;
	int		left;
	int		right;
	int		ur_corner;
	int		ul_corner;
	int		dr_corner;
	int		dl_corner;
	int		enemy_last_x;
	int		enemy_last_y;
	int		enemy_curr_x;
	int		enemy_curr_y;
	int		my_furthest_x;
	int		my_furthest_y;
	int		enemy_furthest_x;
	int		enemy_furthest_y;
	int		nks;//
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
	int		nks;
	// int		piece_x;
	// int		piece_y;
	// char	**piece;
	// char	**temp_piece;
	char	*line;
	char	*input;
	int		fd1;
}				t_fie;

void	print_test(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece);// <---------------
void	first_input(t_fie *filler, t_hmap *heatmap);
void	get_token(t_fie *filler);
void	update_field(t_fie *filler);
int		create_field(t_fie *filler, t_hmap *heatmap);
void	get_size_piece(t_fie *filler, t_pie *piece);
void	get_offset(t_fie *filler, t_pie *piece);
void	update_game(t_fie *filler, t_hmap *heatmap, t_str *strategy, t_pie *piece);
void	update_piece(t_fie *filler, t_hmap *heatmap, t_pie *piece);
void	create_piece(t_pie *piece);
void	init_var_update(t_str *strategy, t_pie *piece, t_hmap *heatmap);
void	copy_piece(t_pie *piece, int x, int first_star, int i);
void	error(t_fie *filler, t_hmap *heatmap);
void	main_control(t_fie *filler, t_hmap *heatmap);
void	find_first_piece(t_fie *filler);
int		create_heatmap(t_hmap *heatmap, t_fie *filler);
void	update_heatmap(t_fie *filler, t_hmap *heatmap, t_str *strategy);
void	update_placement_enemy(t_fie *filler, t_hmap *heatmap);
void	update_map(t_fie *filler, t_hmap *heatmap);
void	get_direction_down(t_hmap *heatmap, t_str *strategy, t_fie *filler);
void	get_direction_up(t_hmap *heatmap, t_str *strategy);
void	update_enemy(t_fie *filler, t_hmap *heatmap, t_str *strategy);
void	heatmap_to_zero(t_hmap *heatmap);
void	heatmap_from_down(t_hmap *heatmap);
void	heatmap_from_up(t_hmap *heatmap);
void	heatmap_from_right(t_hmap *heatmap, t_fie *filler);
void	heatmap_from_left(t_hmap *heatmap);
int		redirect_heatmap_to_enemy(t_fie *filler, t_hmap *heatmap, int n);
void	heatmap_to_enemy(t_fie *filler, t_hmap *heatmap);
void	replace_pieces_of_self(t_fie *filler, t_hmap *heatmap);
void	update_direction(t_str *strategy);
void	init_var_first_input(t_fie *filler, t_hmap *heatmap);
void	update_strategy(t_fie *filler, t_str *strategy);
void	get_my_pos_down(t_fie *filler, t_str *strategy);
void	get_my_pos_up(t_fie *filler, t_str *strategy);
void	init_var_strategy(t_fie *filler, t_str *strategy, t_hmap *heatmap);
void	change_strategy(t_str *strategy);
void	get_furthest_pos(t_fie *filler, t_str *strategy);
void	get_enemy_pos_up(t_fie *filler, t_str *strategy);
void	get_enemy_pos_down(t_fie *filler, t_str *strategy);
int		check_placement(t_hmap *heatmap, t_pie *piece, t_fie *filler);
int		get_sum_placement(t_hmap *heatmap, t_pie *piece, int x, int y, t_fie *filler);
void	write_coordinates(t_hmap *heatmap, t_pie *piece);
void	place_piece(t_hmap *heatmap, t_pie *piece, t_fie *filler);
void	last_placement_enemy(t_fie *filler, t_hmap *heatmap);
#endif