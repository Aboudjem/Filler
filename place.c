#include "filler.h"

void	is_possible(t_map *map, t_piece piece, t_pos *pos)
{
}

void	place_piece(t_map map, t_piece piece, t_pos pos)
{
	check_place(&map, piece, &pos);
	printf("%d %d", pos.pos_player_y, pos.pos_player_x);
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
			//dprintf(2, "\nAdv[%c = %d.%d]",pos->adv, pos->pos_adv_y, pos->pos_adv_x);
}

void	check_player(t_map *map, t_pos *pos)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map->map[y][x] != pos->player && map->map[y][x] != '\0')
	{
		while(map->map[y][x] != pos->player && map->map[y][x] != '\0')
				x++;
	if (map->map[y][x] == pos->player)
		{
		pos->player = 'O';
		break ;	
		}
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

void	check_place(t_map *map, t_piece piece, t_pos *pos)
{
	int y;
	int x;
	x = 0;
	y = 0;
	while (map->map[y][x] != pos->player && map->map[y][x] != '\0')
	{
		while(map->map[y][x] != pos->player && map->map[y][x] != '\0')
				x++;
	if (map->map[y][x] == pos->player)
		{
				pos->pos_player_y = y;
				pos->pos_player_x = x;
		}	
	else
		{
		x = 0;
		y++;
		}
	}
	pos->pos_player_y = y;
	pos->pos_player_x = x;
			dprintf(2, "\nPlayer[%c = %d.%d]",pos->player, pos->pos_player_y, pos->pos_player_x);
}

