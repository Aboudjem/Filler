

#include "filler.h"

void		norme_get_top(t_lst *lst, int *right, int *left, int *y)
{
	t_lst	*first;

	first = lst;
	while (lst)
	{
		if (lst->y < *y)
			*y = lst->y;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->y == *y)
		{
			if (lst->x > *right)
				*right = lst->x;
			if (lst->x < *left)
				*left = lst->x;
		}
		lst = lst->next;
	}
}

void		norme_get_bot(t_lst *lst, int *right, int *left, int *y)
{
	t_lst	*first;

	first = lst;
	while (lst)
	{
		if (lst->y > *y)
			*y = lst->y;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->y == *y)
		{
			if (lst->x > *right)
				*right = lst->x;
			if (lst->x < *left)
				*left = lst->x;
		}
		lst = lst->next;
	}
}

void		norme_get_left(t_lst *lst, int *top, int *bot, int *x)
{
	t_lst	*first;

	first = lst;
	while (lst)
	{
		if (lst->x < *x)
			*x = lst->x;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->x == *x)
		{
			if (lst->y > *bot)
				*bot = lst->y;
			if (lst->y < *top)
				*top = lst->y;
		}
		lst = lst->next;
	}
}

void		norme_get_right(t_lst *lst, int *top, int *bot, int *x)
{
	t_lst	*first;

	first = lst;
	while (lst)
	{
		if (lst->x > *x)
			*x = lst->x;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->x == *x)
		{
			if (lst->y > *bot)
				*bot = lst->y;
			if (lst->y < *top)
				*top = lst->y;
		}
		lst = lst->next;
	}
}
