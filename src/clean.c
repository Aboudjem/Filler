/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:31:10 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/27 16:30:45 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_cleaning_limits2(t_piece *p, t_limit *l)
{
	while (l->right > l->left)
	{
		if (is_piece_column_empty(*p, l->right, '.'))
			l->right--;
		else
			break ;
	}
}

void	get_cleaning_limits(t_piece *p, t_limit *l, int y, int x)
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
	get_cleaning_limits2(p, l);
}

void	clean_piece(t_piece *p, int *clean_top, int *clean_left)
{
	t_limit	l;
	int		x;
	int		y;
	int		start;

	x = 0;
	y = 0;
	l.top = 0;
	l.bot = p->height - 1;
	l.left = 0;
	l.right = p->width - 1;
	get_cleaning_limits(p, &l, y, x);
	p->width = (l.right - l.left) + 1;
	p->height = (l.bot - l.top) + 1;
	start = l.top;
	x = 0;
	while (x < p->height)
	{
		ft_strncpy(p->piece[x], p->piece[start] + l.left, p->width);
		p->piece[x][p->width] = '\0';
		start++;
		x++;
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
