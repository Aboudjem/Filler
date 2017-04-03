/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:04:48 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/02 18:16:15 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	free_env(t_env *e)
{
	int	i;

	i = 0;
	while (e->players[i])
		free(e->players[i++]);
	free(e->players);
	i = 0;
	while (e->maps[i])
		free(e->maps[i++]);
	free(e->maps);
}

WINDOW	*init_window(void)
{
	WINDOW	*win;
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	win = newwin(h, w, 0, 0);
	return (win);
}
