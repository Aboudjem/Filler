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
			//dprintf(2, "\nPlayer[%c = %d.%d]",pos->player, pos->pos_player_y, pos->pos_player_x);
}

int		check_place(t_map *map, t_piece piece, int y, int x)
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
			else if (map->map[py + y][px + x] == '.')
				{
					px++;
				}
		}
		py++;
	}
// dprintf(2, "\n<[%d]>\n", touch);
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
				if (check_place(map, piece, y, x) == 0)
					x++;
				else
				{
					printf("%d %d", y,x);
					dprintf(2, "%d %d", y,x);
				}
			}
			x = 0;
			y++;
	}
}

// void	place_piece(t_map map, t_piece piece, t_pos pos)
// {

// 		(void)map;}

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
			//dprintf(2, "\nAdv[%c = %d.%d]",pos->adv, pos->pos_adv_y, pos->pos_adv_x);
}

// void	check_player(t_map *map, t_pos *pos)
// {
// 	int y;
// 	int x;

// 	x = 0;
// 	y = 0;
// 	while (map->map[y][x] != pos->player && map->map[y][x] != '\0')
// 	{
// 		while(map->map[y][x] != pos->player && map->map[y][x] != '\0')
// 			x++;
// 		if (map->map[y][x] == pos->player)
// 		{
// 			pos->player = 'O';
// 			break ;	
// 		}
// 		else
// 		{
// 			x = 0;
// 			y++;
// 		}
// 	}
// 	pos->pos_player_y = y;
// 	pos->pos_player_x = x;
// 			//dprintf(2, "\nPlayer[%c = %d.%d]",pos->player, pos->pos_player_y, pos->pos_player_x);
// }

// void	check_place(t_map *map, t_piece piece, t_pos *pos)
// {
// 	int y;
// 	int x;
// 	x = 0;
// 	y = 0;
// 	while (map->map[y][x] != pos->player && map->map[y][x] != '\0')
// 	{
// 		while(map->map[y][x] != pos->player && map->map[y][x] != '\0')
// 			x++;
// 		if (map->map[y][x] == pos->player)
// 		{
// 			pos->pos_player_y = y;
// 			pos->pos_player_x = x;
// 		}	
// 		else
// 		{
// 			x = 0;
// 			y++;
// 		}
// 	}
// 	pos->pos_player_y = y;
// 	pos->pos_player_x = x;
// 	dprintf(2, "\nPlayer[%c = %d.%d]\n",pos->player, pos->pos_player_y, pos->pos_player_x);
// }

