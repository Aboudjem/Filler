/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:08:41 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/30 19:14:15 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cleaning_limits2(t_piece *p, t_limit *l)
{
	while (l->right > l->left)
	{
		if (is_piece_column_empty(*p, l->right, '.'))
			l->right--;
		else
			break ;
	}
}

void	cleaning_limits(t_piece *p, t_limit *l, int y, int x)
{
	while (y < p->height)
	{
		if (is_line_empty(p->piece[y], '.'))
			l->top++;
		else
			break ;
		y++;
	}
	while (x < p->width)
	{
		if (is_piece_column_empty(*p, x, '.'))
			l->left++;
		else
			break ;
		x++;
	}
	while (l->bot > l->top)
	{
		if (is_line_empty(p->piece[l->bot], '.'))
			l->bot--;
		else
			break ;
	}
	cleaning_limits2(p, l);
}

t_limit	init_limit(int top, int bot, int left, int right)
{
	t_limit	l;

	l.top = top;
	l.bot = bot;
	l.left = left;
	l.right = right;
	return (l);
}

void	clean_piece(t_piece *p, int *clean_top, int *clean_left)
{
	t_limit	l;
	int		start;
	char	*tmp;
	t_coord	c;

	init_coord(&c);
	l = init_limit(0, p->height -1, 0, p->width -1);
	cleaning_limits(p, &l, c.y, c.x);
	p->width = (l.right - l.left) + 1;
	p->height = (l.bot - l.top) + 1;
	start = l.top;
	c.x = 0;
	while (c.x < p->height)
	{
		tmp = ft_strsub(p->piece[start], l.left, p->width);
		free(p->piece[c.x]);
		p->piece[c.x] = ft_strdup(tmp);
		free(tmp);
		start++;
		c.x++;
	}
	*clean_top = l.top;
	*clean_left = l.left;
}

void	get_diff(t_limit *me, t_limit adv)
{
	if (me->bot < adv.top)
		me->diff_y = adv.top - me->bot;
	else
		me->diff_y = me->top - adv.bot;
	if (me->right < adv.left)
		me->diff_x = adv.left - me->right;
	else
		me->diff_x = me->left - adv.right;
}

void	init_coord(t_coord *coord)
{
	coord->y = 0;
	coord->x = 0;
}
