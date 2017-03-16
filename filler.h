

#ifndef FILLER_H
# define FILLER_H

#include "libft/Includes/libft.h"
#include <stdio.h>
#include <string.h>

typedef struct 	s_map
{

		int 	width;
		int 	height;
		char	map[1000][1000];
}				t_map;

typedef struct 	s_piece
{

		int 	width;
		int 	height;
		char	piece[100][100];
}				t_piece;

typedef struct s_pos
{
	char 		player;
	char 		adv;
	int 		pos_adv_y;
	int 		pos_adv_x;
	int 		pos_player_x;
	int 		pos_player_y;
	int 		x;
	int 		y;
}				t_pos;

typedef struct s_limit
{
	int 		top;
	int 		bot;
	int 		left;
	int 		right;
}				t_limit;

typedef struct 	s_lst
{
	int	x;
	int y;
	struct s_lst	*next;
	//struct s_lst	*prev;
//	struct s_lst	*start;
//	struct s_lst	*end;
}				t_lst;


typedef struct 	s_coord
{
	int	x;
	int y;
}				t_coord;

typedef struct 	s_place
{
	t_coord top;
    t_coord bot;
    t_coord left;
    t_coord right;
}				t_place;



void	is_possible(int y, int x, t_piece piece, t_map map);
int		is_column_empty(t_map map, int column, char c);
int		is_line_empty(char *line, char c);
void	clean_piece(t_piece *piece, t_limit *lim);
void	check_advers(t_map *map, t_pos *pos);
void	check_player(t_map *map, t_pos *pos);
void	place_piece(t_map map, t_piece piece, t_pos pos);
int 	check_place(t_map *map, t_piece piece, int y, int x, t_pos pos);
t_lst	*check_map(t_map *map, t_piece piece, t_pos *pos);
void	print_lst(t_lst *lst);
t_coord	get_top_y(t_lst *lst, t_map *map);
t_coord	get_bot_y(t_lst *lst, t_map *map);
t_coord	get_left_x(t_lst *lst, t_map *map);
t_coord	get_right_x(t_lst *lst, t_map *map);
t_place check_piece(t_lst *lst, t_piece *piece, t_map *map, t_pos *pos);
int	line_contain(char *line, char c);
int	column_contain(t_map map, int column, char c);

# endif
