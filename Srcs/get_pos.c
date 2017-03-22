#include "filler.h"

t_topbot	get_top(t_lst *lst, t_map *map)
{
	t_topbot top;


	int y = map->height;
	int left = map->width;
	int right = 0;
	t_lst *first = lst;
	while(lst)
	{
		if (lst->y < y)
			y = lst->y;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->y == y)
		{
			if (lst->x > right)
				right = lst->x;
			if (lst->x < left)
				left = lst->x;
		}
		lst = lst->next;
	}
	top.left.x = left;
	top.left.y = y;
	top.right.x = right;
	top.right.y = y;
	return (top);
}

t_topbot	get_bot(t_lst *lst, t_map *map)
{
	t_topbot bot;

	int y = 0;
	int left = map->width;
	int right = 0;
	t_lst *first = lst;
	while(lst)
	{
		if (lst->y > y)
			y = lst->y;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->y == y)
		{
			if (lst->x > right)
				right = lst->x;
			if (lst->x < left)
				left = lst->x;
		}
		lst = lst->next;
	}
	bot.left.x = left;
	bot.left.y = y;
	bot.right.x = right;
	bot.right.y = y;
	return(bot);
}

t_leftright	get_left(t_lst *lst, t_map *map)
{
	t_leftright	left;

	int x = map->width;
	int top = map->height;
	int bot = 0;
	t_lst *first = lst;
	while(lst)
	{
		if (lst->x < x)
			x = lst->x;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->x == x)
		{
			if (lst->y > bot)
				bot = lst->y;
			if (lst->y < top)
				top = lst->y;
		}
		lst = lst->next;
	}
	left.top.x = x;
	left.top.y = top;
	left.bot.x = x;
	left.bot.y = bot;
	return (left);

}

t_leftright	get_right(t_lst *lst, t_map *map)
{
	t_leftright	right;

	int x = 0;
	int top = map->height;
	int bot = 0;
	t_lst *first = lst;
	while(lst)
	{
		if (lst->x > x)
			x = lst->x;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->x == x)
		{
			if (lst->y > bot)
				bot = lst->y;
			if (lst->y < top)
				top = lst->y;
		}
		lst = lst->next;
	}
	right.top.x = x;
	right.top.y = top;
	right.bot.x = x;
	right.bot.y = bot;
	return (right);
}
