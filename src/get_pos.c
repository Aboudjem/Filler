

#include "filler.h"

t_topbot	get_top(t_lst *lst, t_map *map)
{
	int			y;
	t_topbot	top;
	int			left;
	int			right;

	y = map->height;
	left = map->width;
	right = 0;
	norme_get_top(lst, &right, &left, &y);
	top.left.x = left;
	top.left.y = y;
	top.right.x = right;
	top.right.y = y;
	return (top);
}

t_topbot	get_bot(t_lst *lst, t_map *map)
{
	int			y;
	t_topbot	bot;
	int			left;
	int			right;

	y = 0;
	left = map->width;
	right = 0;
	norme_get_bot(lst, &right, &left, &y);
	bot.left.x = left;
	bot.left.y = y;
	bot.right.x = right;
	bot.right.y = y;
	return (bot);
}

t_leftright	get_left(t_lst *lst, t_map *map)
{
	int			x;
	int			top;
	int			bot;
	t_leftright	left;

	x = map->width;
	top = map->height;
	bot = 0;
	norme_get_left(lst, &top, &bot, &x);
	left.top.x = x;
	left.top.y = top;
	left.bot.x = x;
	left.bot.y = bot;
	return (left);
}

t_leftright	get_right(t_lst *lst, t_map *map)
{
	int			x;
	int			top;
	int			bot;
	t_leftright	right;

	x = 0;
	bot = 0;
	top = map->height;
	norme_get_right(lst, &top, &bot, &x);
	right.top.x = x;
	right.top.y = top;
	right.bot.x = x;
	right.bot.y = bot;
	return (right);
}
