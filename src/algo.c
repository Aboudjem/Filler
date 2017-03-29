

#include "filler.h"

void	starting_at_bot_medium_map(t_filler f, t_coord c)
{
	int i;

	i = 0;
	get_diff(&f.me, f.adv);
	if (f.me.left != 0 && f.me.top != 0)
	{
		if (f.me.top - f.adv.bot > 4)
			ft_printf("%d %d\n", f.p.left.top.y - c.y, f.p.left.top.x - c.x);
		else
			ft_printf("%d %d\n", f.p.left.bot.y - c.y, f.p.left.bot.x - c.x);
	}
	else
	{
		if (f.me.bot < f.adv.bot)
			ft_printf("%d %d\n", f.p.bot.right.y - c.y, f.p.bot.right.x - c.x);
		else
			ft_printf("%d %d\n", f.p.top.right.y - c.y, f.p.top.right.x - c.x);
	}
}

void	starting_at_bot_small_map(t_filler f, t_coord c)
{
	int	i;

	i = 0;
	get_diff(&f.me, f.adv);
	if (f.me.top != 0)
	{
		if (f.adv.top - f.me.top > 0)
			ft_printf("%d %d\n", f.p.top.left.y - c.y, f.p.top.left.x - c.x);
		else
			ft_printf("%d %d\n", f.p.top.right.y - c.y, f.p.top.right.x - c.x);
	}
	else
	{
		if (f.adv.bot > f.me.bot)
			ft_printf("%d %d\n", f.p.left.bot.y - c.y, f.p.left.bot.x - c.x);
		else
			ft_printf("%d %d\n", f.p.bot.left.y - c.y, f.p.bot.left.x - c.x);
	}
}

void	resolve_all(t_filler f, t_coord c)
{
	get_diff(&f.me, f.adv);
	if (f.players.pos_player_y < f.players.pos_adv_y)
		starting_at_top(f, c);
	else
	{
		if (f.map.height <= 16)
			starting_at_bot_small_map(f, c);
		else if (f.map.height <= 90)
			starting_at_bot_medium_map(f, c);
		else
			starting_at_bot_big_map(f, c);
	}
}

void	starting_at_top(t_filler f, t_coord c)
{
	int div;

	if (f.map.height >= 100)
		div = f.map.height / 10;
	else
		div = 1;
	if (f.me.diff_y > div)
		ft_printf("%d %d\n", f.p.right.bot.y - c.y, f.p.right.bot.x - c.x);
	else
	{
		if (f.me.right == f.map.width - 1 || f.me.top == 0)
		{
			if (f.me.left != 0)
				ft_printf("%d %d\n", f.p.left.top.y - c.y,
						f.p.left.top.x - c.x);
			else
				ft_printf("%d %d\n", f.p.bot.right.y - c.y,
						f.p.bot.right.x - c.x);
		}
		else
			ft_printf("%d %d\n", f.p.top.right.y - c.y, f.p.top.right.x - c.x);
	}
}

void	starting_at_bot_big_map(t_filler f, t_coord c)
{
	int	i;

	i = 0;
	get_diff(&f.me, f.adv);
	if (f.me.top + 2 > f.adv.bot)
		ft_printf("%d %d\n", f.p.left.top.y - c.y, f.p.left.top.x - c.x);
	else if (f.me.right != f.map.width - 1)
		ft_printf("%d %d\n", f.p.right.top.y - c.y, f.p.right.top.x - c.x);
	else if (f.me.left != 0)
		ft_printf("%d %d\n", f.p.left.top.y - c.y, f.p.left.top.x - c.x);
	else if (f.me.top != 0)
		ft_printf("%d %d\n", f.p.top.left.y - c.y, f.p.top.left.x - c.x);
	else
	{
		if (i < 10)
			ft_printf("%d %d\n", f.p.right.top.y - c.y, f.p.right.top.x - c.x);
		else
			ft_printf("%d %d\n", f.p.top.left.y - c.y, f.p.top.left.x - c.x);
	}
}
