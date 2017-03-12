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

void	clean_piece(t_piece *piece, t_lim *lim)
{

		int x = 0;
		int y = 0;
		lim->top = 0;
		lim->bot = piece->height;
		lim->left = 0;
		lim->right = piece->width - 1;

		// On cherche l'index de la premiere ligne
		while (y < piece->height)
		{
				if (is_line_empty(piece->piece[y]))
						lim->top++;
				else
						break ;
				y++;
		}
		dprintf(2,"Top Limit: [%d]\n", lim->top);

		// On cherche l'index de la premiere colonne
		while (x < piece->width)
		{
				if (is_column_empty(*piece, x))
						lim->left++;
				else
						break ;
				x++;
		}
		dprintf(2,"Left Limit: [%d]\n", lim->left);

		// On cherche l'index de la derniere ligne
		while (lim->bot > lim->top)
		{
				if (is_line_empty(piece->piece[lim->bot]))
						lim->bot--;
				else
						break ;
		}
		dprintf(2,"Bottom Limit: [%d]\n", lim->bot);

		// On cherche l'index de la derniere colonne
		while (lim->right > lim->left)
		{
				if (is_column_empty(*piece, lim->right))
						lim->right--;
				else
						break ;
		}
		dprintf(2, "Right Limit: [%d]\n", lim->right);

		// J'actualise la hauteur et la largeur du puzzle dans la structure
		piece->width = (lim->right - lim->left) + 1;
		piece->height = (lim->bot - lim->top) + 1;

		// Je modifie la piece en supprimant la partie rogner
		int i = 0;
		int start = lim->top;
		while (i < piece->height)
		{
				ft_strncpy(piece->piece[i], piece->piece[start]+lim->left, piece->width);
				piece->piece[i][piece->width]='\0';
				start++;
				i++;
		}
}
