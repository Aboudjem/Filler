/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:55:52 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/26 13:59:27 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_topbot	get_top(t_lst *lst, t_map *map)
{
	int			y;
	t_topbot	top;
	int			left;
	int			right;
	t_lst		*first;

	y = map->height;
	left = map->width;
	right = 0;
	first = lst;
	while (lst)
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
	int			y;
	t_topbot	bot;
	int			left;
	int			right;
	t_lst		*first;

	y = 0;
	left = map->width;
	right = 0;
	first = lst;
	while (lst)
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
	return (bot);
}

t_leftright	get_left(t_lst *lst, t_map *map)
{
	int			x;
	int			top;
	int			bot;
	t_lst		*first;
	t_leftright	left;

	x = map->width;
	top = map->height;
	bot = 0;
	first = lst;
	while (lst)
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
	int			x;
	int			top;
	int			bot;
	t_lst		*first;
	t_leftright	right;

	x = 0;
	bot = 0;
	top = map->height;
	first = lst;
	while (lst)
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
