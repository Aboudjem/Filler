#include "filler.h"

int		is_line_empty(char *line)
{
		int x = 0;
		while (line[x])
		{
				if (line[x] != '.')
						return (0);
				x++;
		}
		return (1);
}

int		is_column_empty(t_piece piece, int column)
{
		int y = 0;
		while (y < piece.height)
		{
				if (piece.piece[y][column] != '.')
						return (0);
				y++;
		}
		return (1);
}

void	clean_piece(t_piece *piece)
{
		int x = 0;
		int y = 0;
		int top_limit = 0;
		int bottom_limit = piece->height;
		int left_limit = 0;
		int right_limit = piece->width - 1;

		// On cherche l'index de la premiere ligne
		while (y < piece->height)
		{
				if (is_line_empty(piece->piece[y]))
						top_limit++;
				else
						break ;
				y++;
		}
		printf("Top Limit: [%d]\n", top_limit);

		// On cherche l'index de la premiere colonne
		while (x < piece->width)
		{
				if (is_column_empty(*piece, x))
						left_limit++;
				else
						break ;
				x++;
		}
		printf("Left Limit: [%d]\n", left_limit);

		// On cherche l'index de la derniere ligne
		while (bottom_limit > top_limit)
		{
				if (is_line_empty(piece->piece[bottom_limit]))
						bottom_limit--;
				else
						break ;
		}
		printf("Bottom Limit: [%d]\n", bottom_limit);

		// On cherche l'index de la derniere colonne
		while (right_limit > left_limit)
		{
				if (is_column_empty(*piece, right_limit))
						right_limit--;
				else
						break ;
		}
		printf("Right Limit: [%d]\n", right_limit);

		// J'actualise la hauteur et la largeur du puzzle dans la structure
		piece->width = (right_limit - left_limit) + 1;
		piece->height = (bottom_limit - top_limit) + 1;

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
}
