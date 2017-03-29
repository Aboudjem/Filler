

#include "filler.h"

void	get_player(t_players *players)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strncmp("# -----", line, 6) == 0)
	{
		while (ft_strncmp("launched players/ab", line, 19) != 0)
			get_next_line(0, &line);
		get_next_line(0, &line);
		if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
		{
			get_next_line(0, &line);
			get_next_line(0, &line);
		}
	}
	players->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
	players->adv = players->player == 'O' ? 'X' : 'O';
}

t_place	check_piece(t_lst *lst, t_map *map)
{
	t_place	place;

	place.top = get_top(lst, map);
	place.left = get_left(lst, map);
	place.bot = get_bot(lst, map);
	place.right = get_right(lst, map);
	return (place);
}

t_lst	*check_map(t_filler f)
{
	t_coord coord;
	t_lst	*lst;

	coord.y = 0;
	lst = NULL;
	while (coord.y < f.map.height)
	{
		coord.x = 0;
		while (coord.x < f.map.width)
		{
			if (can_place_piece(f, coord) == 1)
				lst = add_placable(lst, coord.x, coord.y);
			coord.x++;
		}
		coord.y++;
	}
	return (lst);
}

void	norme_get_limits(t_limit *lim, t_coord *coord, t_map *map, char c)
{
	while (coord->x < map->width)
	{
		if (column_contain(*map, coord->x, c))
			break ;
		else
			lim->left++;
		coord->x++;
	}
	while (lim->bot > lim->top)
	{
		if (line_contain(map->map[lim->bot], c))
			break ;
		else
			lim->bot--;
	}
	while (lim->right > lim->left)
	{
		if (column_contain(*map, lim->right, c))
			break ;
		else
			lim->right--;
	}
}

t_limit	get_limits(t_map *map, char c)
{
	t_coord coord;
	t_limit lim;

	init_coord(&coord);
	lim.top = 0;
	lim.bot = map->height;
	lim.left = 0;
	lim.right = map->width - 1;
	while (coord.y < map->height)
	{
		if (line_contain(map->map[coord.y], c))
			break ;
		else
			lim.top++;
		coord.y++;
	}
	norme_get_limits(&lim, &coord, map, c);
	return (lim);
}

int		main(void)
{
	t_filler	filler;
	t_lst		*lst;
	t_coord		c;
	int			first_time;

	first_time = 0;
	init_coord(&c);
	get_player(&filler.players);
	while (42)
	{
		get_map(&filler.map);
		if (first_time == 0)
			start(&filler.players, filler.map, &first_time);
		get_piece(&filler.piece);
		clean_piece(&filler.piece, &c.y, &c.x);
		lst = check_map(filler);
		filler.me = get_limits(&filler.map, filler.players.player);
		filler.adv = get_limits(&filler.map, filler.players.adv);
		filler.p = check_piece(lst, &filler.map);
		resolve_all(filler, c);
	}
	return (0);
}
