

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


int		is_column_empty(t_piece piece, int column);
int		is_line_empty(char *line);
void	clean_piece(t_piece *piece);

# endif
