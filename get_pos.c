#include "fillit.h"

void	get_top_y()
{
	int y = map->height;
	int x = map->width;
	while(lst)
	{
		if (lst->y < y)
		{
			y = lst->y
			x = lst->x
		}
		lst = lst->next;
	}
}


//recupere la coordonnee la plus en bas
void	get_bot_y()
{
	int y = 0;
	int x = 0;
	while(lst)
	{
		if (lst->y > y)
		{
			y = lst->y
			x = lst->x
		}
		lst = lst->next;
	}
}

//recupere la coordonnee la plus a droite
void	get_right_x()
{
	int y = map->height;
	int x = map->width;
	while(lst)
	{
		if (lst->x < x)
		{
			y = lst->y
			x = lst->x
		}
		lst = lst->next;
	}
}

//recupere la coordonnee la plus a gauche
void	get_left_x()
{
	int y = 0;
	int x = 0;
	while(lst)
	{
		if (lst->x > x)
		{
			y = lst->y
			x = lst->x
		}
		lst = lst->next;
	}
}