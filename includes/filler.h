/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:26:16 by plisieck          #+#    #+#             */
/*   Updated: 2017/04/01 21:18:42 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <string.h>
# include <curses.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <unistd.h>

/*
 ** CONFIGURATION
*/
# define SETCOLORS 0
# define P1_COLOR CYAN
# define P2_COLOR WHITE
# define BG_COLOR BLUE

# define G_WHITE 1
# define G_GREY 2
# define G_ROUGE 3
# define G_VERT 4
# define G_DARKBLUE 5
# define G_CYAN 6
# define G_JAUNE 7
# define G_MAUVE 8
# define G_PINK 9
# define G_GREEN 10

# define T_WHITE 11
# define T_GREY 12
# define T_ROUGE 13
# define T_VERT 14
# define T_DARKBLUE 15
# define T_CYAN 16
# define T_JAUNE 17
# define T_MAUVE 18
# define T_PINK 19
# define T_GREEN 20
# define ESCAPE 27
# define P1_COLOR_BG G_GREEN
# define P2_COLOR_BG G_ROUGE
# define P1_COLOR_TXT T_GREEN
# define P2_COLOR_TXT T_ROUGE

/*
 ** BASIC BONUS
*/
# define END      "\033[0m"
# define BOLD       "\033[1m"
# define ITALIC     "\033[3m"
# define UNDERLINE  "\033[4m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

/*
 ** COLOR DEFINES
*/
# define COLOR_GREY 100
# define COLOR_ROUGE 122
# define COLOR_VERT 110
# define COLOR_DARKBLUE 128
# define COLOR_JAUNE 60
# define COLOR_MAUVE 134
# define COLOR_PINK 156

typedef struct	s_print
{
	char	*p1;
	char	*p2;
	int		score_p1;
	int		score_p2;
}				t_print;

typedef struct	s_mapw
{
	char	*o;
	char	*x;
	char	*dot;
}				t_mapw;

typedef struct	s_env
{
	char	**players;
	char	**maps;
	int		nb_players;
	int		nb_maps;
}				t_env;

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
t_limit			get_limits(t_map *map, char c);
t_limit			init_limit(int top, int bot, int left, int right);

/*
 ** Bonus Graph
*/
void			init_colors(void);
void			init_pairs(void);
void			init_curses(void);
void			color_line(char *map, WINDOW *box);
void			norme_print_map(t_coord c, char *line, WINDOW *box);
void			print_map(t_print *print, char *line, t_coord c, WINDOW *box);
void			print_score(t_print print, WINDOW *box);
void			size_map(char *map, t_mapw *mapw);
void			get_player_name(char *line, t_print *print);
void			clean_player(char *player);
void			get_height(char *line, t_coord *c);

/*
 ** Bonus MatchMaker
*/

void			norme_get_available(t_env *e, int i, char **tab, char *str);
void			get_available(t_env *e, char *str);
int				player_menu2(WINDOW *menu, int choice, char **p, char *player);
int				display_menu(WINDOW *win, t_env e);
void			print_title(WINDOW *menu, int h, int w);
void			print_menu(WINDOW *menu, int choice);
void			print_p1_or_p2(WINDOW *menu, char *player, int h, int w);
void			print_pmenu(WINDOW *menu, int choice, char **p, char *player);
void			print_choosing_map_menu(WINDOW *menu, int choice, char **m);
int				choose_p2(WINDOW *win, t_env e, char *p1);
int				norme_choose_p1(WINDOW *win, t_env e, int choice);
int				choose_p1(WINDOW *win, t_env e);
void			choose_map2(WINDOW *win, t_env e, int choice, t_print players);
int				choose_map(WINDOW *win, t_env e, char *p1, char *p2);
void			free_env(t_env *e);
WINDOW			*init_window(void);

#endif
