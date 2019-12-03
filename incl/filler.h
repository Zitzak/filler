/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:01 by mgross         #+#    #+#                */
/*   Updated: 2019/10/14 18:32:00 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

# define BUFF_SIZE_FILLER	1024
# define START_TOP			(1 << 0)
# define START_BOTT			(1 << 1)
# define STR_DIAG			(1 << 5)

typedef	struct	s_hmap
{
	int			**map;
	int			size_x;
	int			size_y;
	int			enemy_num;
	int			sum;
	int			x;
	int			y;
	int			start;
}				t_hmap;

typedef struct	s_pie
{
	int			star;
	int			x;
	int			y;
	int			piece_x;
	int			piece_y;
	int			last_star;
	int			first_star;
	int			first_line;
	int			lines_piece;
	int			collums_piece;
	char		**piece;
	char		**temp_piece;
}				t_pie;

typedef struct	s_fie
{
	char		me;
	char		enemy;
	short		start;
	int			field_x;
	int			field_y;
	char		**field;
	char		*line;
}				t_fie;

int				first_input(t_fie *filler, t_hmap *heatmap);
int				update_field(t_fie *filler, t_hmap *heatmap);
int				update_game(t_fie *filler, t_hmap *heatmap, t_pie *piece);
int				update_piece(t_fie *filler, t_pie *piece);
int				main_control(t_fie *filler, t_hmap *heatmap, t_pie *piece);
void			update_heatmap(t_fie *filler, t_hmap *heatmap);
void			update_enemy(t_fie *filler, t_hmap *heatmap);
void			heatmap_to_enemy(t_hmap *heatmap);
int				check_placement(t_hmap *heatmap, t_pie *piece);
int				get_sum_placement(t_hmap *heatmap, t_pie *piece, int x, int y);
void			free_piece(t_pie *piece);
void			free_filler(t_fie *filler);
void			update_coord_placement(t_hmap *heatmap, int sum, int x, int y);
int				get_sum_redirect(t_hmap *heatmap, t_pie *piece, int x,
				int temp_y);
void			free_line(t_fie *filler);

#endif
