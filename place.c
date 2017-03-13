#include "filler.h"

void		start(t_pos *pos, t_map map)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map.map[y][x] != pos->player && map.map[y][x] != '\0')
	{
		while(map.map[y][x] != pos->player && map.map[y][x] != '\0')
			x++;
		if (map.map[y][x] == pos->player)
			break ;	
		else
		{
			x = 0;
			y++;
		}
	}
	pos->pos_player_y = y;
	pos->pos_player_x = x;
}

int		can_place_piece(t_map *map, t_piece piece, int y, int x)
{
	int py;
	int	px;
	int	touch;
	touch = 0;

	py = 0;
	while(py < piece.height)
	{
		px = 0;
		while (px < piece.width)
		{
			if (piece.piece[py][px] == '*')
			{
				if (map->map[y + py][x + px] == 'O')
					touch++;
				px++;
			}
			/* else if (map->map[py + y][px + x] == '.')
			{
				px++;
			}
			*/
			else
				px++;
		}
		py++;
	}
	if (touch == 1)
		return(1);
	else
		return(0);
}

void	check_map(t_map *map, t_piece piece, t_pos *pos, t_lim lim)
{
	int y;
	int x;
	x = 0;
	y = 0;
	while(y < map->height)
	{
		while (x < map->width)
		{

			if (can_place_piece(map, piece, y, x) == 1)
			{
				//dprintf(2, "[%d %d]\n", y,x);
				ft_printf("%d %d\n", y, x);
				//ft_putnbr(y);
				//ft_putstr(" ");
				//ft_putnbr(x);
				//ft_putendl("");
				return ;
			}
			else
			{
				x++;
			}
		}
		x = 0;
		y++;
	}
}

void	check_advers(t_map *map, t_pos *pos)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map->map[y][x] != pos->adv && map->map[y][x] != '\0')
	{
		while(map->map[y][x] != pos->adv && map->map[y][x] != '\0')
			x++;
		if (map->map[y][x] == pos->adv)
			break ;	
		else
		{
			x = 0;
			y++;
		}
	}
	pos->pos_adv_y = y;
	pos->pos_adv_x = x;
}
