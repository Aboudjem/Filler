#include "filler.h"

void		start(t_players *players, t_map map, int *i)
{
	int y;
	int x;

	y = 0;
	while(y < map.height)
	{
		x = 0;
		while(map.map[y][x])
		{
			if (map.map[y][x] == players->player)
			{
				players->pos_player_y = y;
				players->pos_player_x = x;
			}	
			else if (map.map[y][x] == players->adv)
			{	
				players->pos_adv_y = y;
				players->pos_adv_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	
	*i = 1;
}

int		can_place_piece(t_map *map, t_piece piece, int y, int x, t_players *players)
{
	int py;
	int	px;
	int	touch;
	touch = 0;
	py = 0;

	while(py < piece.height && ((y+piece.height) <= map->height))
	{
		px = 0;
		while (px < piece.width && ((x+piece.width) <= map->width))
		{
			if (piece.piece[py][px] == '*')
			{
				if (map->map[y + py][x + px] == players->player)
					touch++;
				else if(map->map[y + py][x + px] == players->adv)
					return(0);
				px++;
			}
			else if (piece.piece[py][px] == '.')
			{
				if (map->map[y + py][x + px]  == players->adv)
					return(0);
				px++;
			}
		}
		py++;
	}
	if (touch == 1)
		return(1);
	else
		return(0);
}

/*
   t_lst	*add_placable(t_lst *lst, int x, int y)
   {
   t_lst	*new_element;

   new_element = malloc(sizeof(t_lst));
   new_element->x = x;
   new_element->y = y;
   if (!lst)
   return (new_element);
   while (lst->next)
   lst = lst->next;
   lst->next = new_element;
   new_element->prev= lst;
   new_element->next = NULL;
   return (new_element);
   }

*/

t_lst	*add_placable(t_lst *lst, int x, int y)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->next = lst;
	}
	return tmp;

}

void	print_lst(t_lst *lst)
{
	while(lst)
	{
		ft_putstr_fd(">----->[", 2);
		ft_putnbr_fd(lst->y, 2);
		ft_putstr_fd(".", 2);
		ft_putnbr_fd(lst->x, 2);
		ft_putendl_fd("]<-----<\n", 2);
		lst = lst->next;
	}
}

t_lst	*check_map(t_map *map, t_piece piece, t_players *players)
{
	int y;
	int x;
	t_lst	*lst;

	y = 0;
	lst = NULL;
	while(y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			//dprintf(2, "Y[%d] X[%d]\n", y, x);
			if (can_place_piece(map, piece, y, x, players) == 1)
			{
				lst = add_placable(lst, x, y);}
			x++;
		}
		y++;
	}
	return (lst);
}

void	check_advers(t_map *map, t_players *players)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map->map[y][x] != players->adv && map->map[y][x] != '\0')
	{
		while(map->map[y][x] != players->adv && map->map[y][x] != '\0')
			x++;
		if (map->map[y][x] == players->adv)
			break ;	
		else
		{
			x = 0;
			y++;
		}
	}
	players->pos_adv_y = y;
	players->pos_adv_x = x;
}
