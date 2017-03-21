#include "filler.h"

int		is_line_empty(char *line, char c)
{
	int x = 0;
	while (line[x])
	{
		if (line[x] != c)
			return (0);
		x++;
	}
	return (1);
}

int		is_piece_column_empty(t_piece piece, int column, char c)
{
	int y = 0;
	while (y < piece.height)
	{
		if (piece.piece[y][column] != c)
			return (0);
		y++;
	}
	return (1);
}

int		is_column_empty(t_map map, int column, char c)
{
	int y = 0;
	while (y < map.height)
	{
		if (map.map[y][column] != c)
			return (0);
		y++;
	}
	return (1);
}

int	line_contain(char *line, char c)
{
	int x = 0;
	while (line[x])
	{
		if (line[x] == c)
			return (1);
		x++;
	}
	return (0);
}

int	column_contain(t_map map, int column, char c)
{
	int y = 0;
	while (y < map.height)
	{
		if (map.map[y][column] == c)
			return (1);
		y++;
	}
	return (0);
}

void	clean_piece(t_piece *piece, int *cleaned_top, int *cleaned_left)
{
    int x = 0;
    int y = 0;
    int top_limit = 0;
    int bottom_limit = piece->height - 1;
    int left_limit = 0;
    int right_limit = piece->width - 1;

	(void)cleaned_top;
	(void)cleaned_left;
    
    // On cherche l'index de la premiere ligne
    while (y < piece->height)
    {
        if (is_line_empty(piece->piece[y], '.'))
            top_limit++;
        else
            break ;
        y++;
    }
    
    // On cherche l'index de la premiere colonne
    while (x < piece->width)
    {
        if (is_piece_column_empty(*piece, x, '.'))
            left_limit++;
        else
            break ;
        x++;
    }
    
    // On cherche l'index de la derniere ligne
    while (bottom_limit > top_limit)
    {
        if (is_line_empty(piece->piece[bottom_limit], '.'))
            bottom_limit--;
        else
            break ;
    }
    
    // On cherche l'index de la derniere colonne
    while (right_limit > left_limit)
    {
        if (is_piece_column_empty(*piece, right_limit, '.'))
            right_limit--;
        else
            break ;
    }
    
    // J'actualise la hauteur et la largeur du puzzle dans la structure
   
   		
//	dprintf(2, "L[%d]R[%d]\n", left_limit, right_limit);
//	dprintf(2, "T[%d]B[%d]\n", top_limit, bottom_limit);
	piece->width = (right_limit - left_limit) + 1;
    piece->height = (bottom_limit - top_limit) + 1;
    
// 	dprintf(2, "{{%d}}{{%d}}\n", piece->height, piece->width);

    // Je modifie la piece en supprimant la partie rogner
    int i = 0;
    int start = top_limit;
    while (i < piece->height)
    {
        ft_strncpy(piece->piece[i], piece->piece[start]+left_limit, piece->width);
        piece->piece[i][piece->width]='\0';
		start++;
		i++;
    }
	*cleaned_top = top_limit;
	*cleaned_left = left_limit;
}

