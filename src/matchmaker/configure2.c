#include "../../includes/filler.h"

void	choice_config_p2(t_maker *m)
{
	if (m->choice == 10)
		m->c.p2 = 22;
	else if (m->choice == 11)
		m->c.p2 = G_GREY;
	else if (m->choice == 12)
		m->c.p2 = G_ROUGE;
	else if (m->choice == 13)
		m->c.p2 = G_GREEN;
	else if (m->choice == 14)
		m->c.p2 = G_DARKBLUE;
	else if (m->choice == 15)
		m->c.p2 = G_CYAN;
	else if (m->choice == 16)
		m->c.p2 = G_JAUNE;
	else if (m->choice == 17)
		m->c.p2 = G_MAUVE;
	else if (m->choice == 18)
		m->c.p2 = G_PINK;
	m->choice = 9;
	wclear(m->win);
	wrefresh(m->win);
}

void	choice_config_p1(t_maker *m)
{
	if (m->choice == 0)
		m->c.p1 = 22;
	else if (m->choice == 1)
		m->c.p1 = G_GREY;
	else if (m->choice == 2)
		m->c.p1 = G_ROUGE;
	else if (m->choice == 3)
		m->c.p1 = G_VERT;
	else if (m->choice == 4)
		m->c.p1 = G_DARKBLUE;
	else if (m->choice == 5)
		m->c.p1 = G_CYAN;
	else if (m->choice == 6)
		m->c.p1 = G_JAUNE;
	else if (m->choice == 7)
		m->c.p1 = G_MAUVE;
	else if (m->choice == 8)
		m->c.p1 = G_PINK;
	m->choice = 10;
	wclear(m->win);
	wrefresh(m->win);
}

void	norme_choice_config(t_maker *m)
{
	m->choice -= ((m->key == KEY_UP) && ((m->choice > 0
	&& m->choice <= 9) || (m->choice > 10 && m->choice <= 19))) ? 1 : 0;
	m->choice -= ((m->key == KEY_LEFT) && (m->choice >= 10)) ? 10 : 0;
	m->choice += ((m->key == KEY_RIGHT) && (m->choice <= 8)) ? 10 : 0;
	m->choice += ((m->key == KEY_DOWN) && ((m->choice <= 8)
	|| (m->choice >= 10 && m->choice <= 18))) ? 1 : 0;
}

int		configure(t_maker *m)
{
	m->choice = 0;
	while ((m->key = getch()) != ESCAPE)
	{
		norme_choice_config(m);
		if (m->key == ' ' || m->key == '\n')
		{
			if (m->choice >= 0 && m->choice <= 8)
				choice_config_p1(m);
			else if (m->choice >= 10 && m->choice <= 18)
				choice_config_p2(m);
			else
			{
				m->choice = 0;
				wclear(m->win);
				wrefresh(m->win);
				return (0);
			}
		}
		print_configure(m);
		wrefresh(m->win);
	}
	wclear(m->win);
	endwin();
	return (0);
}
