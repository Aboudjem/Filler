/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:20:30 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:20:33 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(t_flags *f, t_conv *t)
{
	f->d_used = 1;
	if (f->h == 1)
		t->d = (short)va_arg(t->arguments, long long int);
	else if (f->hh == 1 && f->h == 0)
		t->d = (char)va_arg(t->arguments, long long int);
	else if (f->ll == 1 || f->l == 1)
		t->d = (long long)va_arg(t->arguments, long long);
	else if (f->j == 1)
		t->d = (intmax_t)va_arg(t->arguments, long long);
	else if (f->z == 1)
		t->d = (ssize_t)va_arg(t->arguments, long long);
	else
		t->d = (int)va_arg(t->arguments, long long int);
}

void	get_length_u(t_flags *f, t_conv *t)
{
	f->u_used = 1;
	if (f->h == 1)
		t->u = (unsigned short)va_arg(t->arguments, unsigned long long int);
	else if (f->hh == 1)
		t->u = (unsigned char)va_arg(t->arguments, unsigned long long int);
	else if (f->l == 1 || f->ll == 1)
		t->u = (unsigned long)va_arg(t->arguments, unsigned long long int);
	else if (f->j == 1)
		t->u = (uintmax_t)va_arg(t->arguments, unsigned long long);
	else if (f->z == 1)
		t->u = (size_t)va_arg(t->arguments, unsigned long long);
	else
		t->u = (unsigned int)va_arg(t->arguments, unsigned long long int);
}

void	which_length(const char *s, int i, t_flags *f)
{
	if (s[i] == 'l' && s[i + 1] == 'l')
		f->ll = 1;
	else if (s[i] == 'l' && s[i + 1] != 'l' && f->ll == 0)
		f->l = 1;
	else if (s[i] == 'j')
		f->j = 1;
	else if (s[i] == 'z')
		f->z = 1;
	if (s[i] == 'h' && s[i + 1] == 'h')
		f->hh = 1;
	else if (s[i] == 'h' && s[i + 1] != 'h' && f->hh == 0)
		f->h = 1;
}

void	modif_length2(t_flags *f, t_conv *t)
{
	if (t->conv == 'U')
	{
		t->conv = 'u';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if (t->conv == 'O')
	{
		t->conv = 'o';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if (t->conv == 'C')
	{
		t->conv = 'C';
		f->hh = 0;
		f->h = 0;
	}
}

void	modif_length(t_flags *f, t_conv *t)
{
	if (t->conv == 'c' && f->l == 1)
	{
		t->conv = 'C';
		f->l = 0;
	}
	else if (t->conv == 's' && f->l == 1)
	{
		t->conv = 'S';
		f->l = 0;
	}
	else if (t->conv == 'D')
	{
		t->conv = 'd';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if ((t->conv == 'U') || (t->conv == 'O') || (t->conv == 'C'))
		modif_length2(f, t);
}
