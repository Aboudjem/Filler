#include "filler.h"

t_coord	get_top_y(t_lst *lst, t_map *map)
{
		t_coord	coord;
		int y = map->height;
		int x = map->width;
		while(lst)
		{
				if (lst->y < y)
				{
						y = lst->y;
						x = lst->x;
				}
				lst = lst->next;
		}
		coord.x = x;
		coord.y = y;
		return (coord);
}

t_coord	get_bot_y(t_lst *lst, t_map *map)
{
		t_coord	coord;
		int y = 0;
		int x = 0;
		while(lst)
		{
				if (lst->y > y)
				{
						y = lst->y;
						x = lst->x;
				}
				lst = lst->next;
		}
		coord.x = x;
		coord.y = y;
		return (coord);
}

t_coord	get_left_x(t_lst *lst, t_map *map)
{
		t_coord	coord;
		int y = map->height;
		int x = map->width;
		while(lst)
		{
				if (lst->x < x)
				{
						y = lst->y;
						x = lst->x;
				}
				lst = lst->next;
		}
		coord.x = x;
		coord.y = y;
		return (coord);

}

t_coord	get_right_x(t_lst *lst, t_map *map)
{
		t_coord	coord;
		int y = 0;
		int x = 0;
		while(lst)
		{
				if (lst->x > x)
				{
						y = lst->y;
						x = lst->x;
				}
				lst = lst->next;
		}
		coord.x = x;
		coord.y = y;
		return (coord);

}
