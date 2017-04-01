/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:26:16 by plisieck          #+#    #+#             */
/*   Updated: 2017/04/01 18:02:10 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "matchmaker.h"
# include <stdio.h>
# include <string.h>

/*
 ** CONFIGURATION
*/
# define SETCOLORS 1
# define P1_COLOR CYAN
# define P2_COLOR WHITE
# define BG_COLOR BLUE


/*
 ** BASIC BONUS
*/
#define END      "\033[0m"
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

/*
 ** COLOR DEFINES
*/
#define COLOR_GREY 100
#define COLOR_ROUGE 122
#define COLOR_VERT 110
#define COLOR_DARKBLUE 128
#define COLOR_JAUNE 60
#define COLOR_MAUVE 134
#define COLOR_PINK 156

typedef	struct	s_map
{

	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int		width;
	int		height;
	int		original_height;
	char	**piece;
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

typedef struct	s_filler
{
	t_place		p;
	t_limit		me;
	t_limit		adv;
	t_map		map;
	t_piece		piece;
	t_players	players;
}				t_filler;

/*
 **	algo.c
*/
void			resolve_all(t_filler f, t_coord c);
void			starting_at_bot_small_map(t_filler f, t_coord c);
void			starting_at_bot_medium_map(t_filler f, t_coord c);
void			starting_at_bot_big_map(t_filler f, t_coord c);
void			starting_at_top(t_filler f, t_coord c);

/*
 **	place.c
*/
void			start(t_players *players, t_map map, int *i);
t_lst			*check_map(t_filler f);
void			check_advers(t_map *map, t_players *players);
t_lst			*add_placable(t_lst *lst, int x, int y);
int				can_place_piece(t_filler f, t_coord coord);

/*
 **	get_pos.c
*/
t_topbot		get_top(t_lst *lst, t_map *map);
t_topbot		get_bot(t_lst *lst, t_map *map);
t_leftright		get_left(t_lst *lst, t_map *map);
t_leftright		get_right(t_lst *lst, t_map *map);

/*
 **	norme_get_pos.c
*/
void			norme_get_top(t_lst *lst, int *right, int *left, int *y);
void			norme_get_bot(t_lst *lst, int *right, int *left, int *y);
void			norme_get_left(t_lst *lst, int *top, int *bot, int *x);
void			norme_get_right(t_lst *lst, int *top, int *bot, int *x);

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
 **	clean.c
*/
void			clean_piece(t_piece *piece, int *clean_top, int *clean_left);
void			cleaning_limits(t_piece *p, t_limit *l, int y, int x);
void			cleaning_limits2(t_piece *p, t_limit *l);
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

/*
 **	get2.c
*/
t_limit	get_limits(t_map *map, char c);
t_limit	init_limit(int top, int bot, int left, int right);

#endif
