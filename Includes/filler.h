#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <string.h>


/*
 ** CONFIGURATION
*/
#define DISPLAY_COLORS 0

typedef	struct	s_map
{

	int		width;
	int		height;
	char	map[1000][1000];
}				t_map;

typedef struct	s_piece
{
	int		width;
	int		height;
	char	piece[100][100];
}				t_piece;

typedef struct	s_players
{
	char		player;
	char		adv;
	int			pos_adv_y;
	int			pos_adv_x;
	int			pos_player_x;
	int			pos_player_y;
}				t_players;

typedef struct	s_limit
{
	int			top;
	int			bot;
	int			left;
	int			right;
	int			diff_y;
	int			diff_x;
}				t_limit;

typedef struct	s_lst
{
	int				x;
	int				y;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_coord
{
	int	x;
	int y;
}				t_coord;

typedef struct	s_topbot
{
	t_coord left;
	t_coord right;
}				t_topbot;

typedef struct	s_leftright
{
	t_coord top;
	t_coord bot;
}				t_leftright;

typedef struct	s_place
{
	t_topbot	top;
	t_topbot	bot;
	t_leftright	left;
	t_leftright	right;
}				t_place;

typedef struct 	s_filler
{
	t_map		map;
	t_players	players;
	t_limit		me;
	t_limit		adv;
	t_place		place;
}				t_filler;

/*
 **	algo.c
*/
t_place			check_piece(t_lst *lst, t_map *map);
void    		resolve_all(t_filler f, t_coord c);
void			starting_at_bot(t_filler f, t_coord c);
void			starting_at_top(t_filler f, t_coord c);

/*
 **	place.c
*/
void			start(t_players *players, t_map map, int *i);
t_lst			*check_map(t_map *map, t_piece piece, t_players *players);
void			check_advers(t_map *map, t_players *players);
t_lst			*add_placable(t_lst *lst, int x, int y);
int				can_place_piece(t_map *map, t_piece piece, t_coord coord, t_players *p);

/*
 **	get_pos.c
*/
t_topbot		get_top(t_lst *lst, t_map *map);
t_topbot		get_bot(t_lst *lst, t_map *map);
t_leftright		get_left(t_lst *lst, t_map *map);
t_leftright		get_right(t_lst *lst, t_map *map);


/*
 **	utils.c
*/
void			get_map(t_map *map);
void			get_size_map(t_map *map);
void			color_map(char *map);
void			get_size_piece(t_piece *piece);
void			get_piece(t_piece *piece);
void			get_player(t_players *players);


/*
 **	clean_utils.c
*/
void			clean_piece(t_piece *piece, int *cleaned_top, int *cleaned_left);
void			get_cleaning_limits(t_piece *p, t_limit *l, int y, int x);
void			get_cleaning_limits(t_piece *p, t_limit *l, int y, int x);
void			init_coord(t_coord *coord);
void			get_diff(t_limit *me, t_limit adv);

/*
 **	clean_utils.c
*/
int				is_line_empty(char *line, char c);
int				is_piece_column_empty(t_piece piece, int column, char c);
int				is_column_empty(t_map map, int column, char c);
int				line_contain(char *line, char c);
int				column_contain(t_map map, int column, char c);

#endif
