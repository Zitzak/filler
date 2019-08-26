/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:01 by mgross         #+#    #+#                */
/*   Updated: 2019/08/26 17:04:59 by Marvin        ########   odam.nl         */
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

typedef	struct 	s_hmap
{
	int		**map;
	int		size_x;
	int		size_y;
	int		enemy_num;
	int		last_piece_x;
	int		last_piece_y;
	int		current_piece_x;
	int		current_piece_y;
}				t_hmap;

typedef struct s_info
{
	char	me;
	int 	fd;// < -------------------
	char	other;
	short	start;
	int		last_star;
	int		first_star;
	int		lines_piece;
	int		collums_piece;
	int		field_x;
	int		field_y;
	char	**field;
	int		piece_x;
	int		piece_y;
	char	**piece;
	char	**temp_piece;
	char	*line;
}				t_info;

void	print_test(t_info *filler, t_hmap *heatmap);// <---------------
void	first_input(t_info *filler, t_hmap *heatmap);
void	get_token(t_info *filler);
void	update_field(t_info *filler);
int		create_field(t_info *filler, t_hmap *heatmap);
void	get_size_piece(t_info *filler);
void	get_offset(t_info *filler);
void	update_game(t_info *filler, t_hmap *heatmap);
void	update_piece(t_info *filler, t_hmap *heatmap);
void	create_piece(t_info *filler);
void	initializing_var_struct(t_info *filler, t_hmap *heatmap);
void	copy_piece(t_info *filler, int x, int first_star, int i);
void	error(t_info *filler, t_hmap *heatmap);
void	main_control(t_info *filler, t_hmap *heatmap);
void	find_first_piece(t_info *filler);
int		create_heatmap(t_hmap *heatmap);
void	update_heatmap(t_info *filler, t_hmap *heatmap);
void	update_placement_enemy(t_info *filler, t_hmap *heatmap);
void	update_map(t_info *filler, t_hmap *heatmap);
void	update_strategy(t_hmap *heatmap);
void	get_direction(t_hmap *heatmap);
void	update_enemy(t_info *filler, t_hmap *heatmap);
void	heatmap_to_zero(t_hmap *heatmap);
void	heatmap_from_down(t_hmap *heatmap);
void	heatmap_from_up(t_hmap *heatmap);
void	heatmap_from_right(t_hmap *heatmap);
void	heatmap_from_left(t_hmap *heatmap);
int		direct_change_heatmap(t_hmap *heatmap, int n);
void	heatmap_to_enemy(t_hmap *heatmap);
void	replace_pieces_of_self(t_info *filler, t_hmap *heatmap);

#endif