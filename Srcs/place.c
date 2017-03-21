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

int		can_place_piece(t_map *map, t_piece piece, int y, int x, t_pos *pos)
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
				if (map->map[y + py][x + px] == pos->player)
					touch++;
				else if(map->map[y + py][x + px] == pos->adv)
					return(0);
				px++;
			}
			else if (piece.piece[py][px] == '.')
			{
				if (map->map[y + py][x + px]  == pos->adv)
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

t_lst	*check_map(t_map *map, t_piece piece, t_pos *pos)
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
			if (can_place_piece(map, piece, y, x, pos) == 1)
			{
				lst = add_placable(lst, x, y);}
			x++;
		}
		y++;
	}
	return (lst);
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
