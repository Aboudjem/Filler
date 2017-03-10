/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:20:50 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:21:09 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_litoa(unsigned long long int n)
{
	unsigned long long int	tmp;
	int						len;
	char					*str;

	tmp = n;
	len = 2;
	while (tmp /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int		ft_wstrcmp(const wchar_t *s1, const wchar_t *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*s1 - *s2);
	}
	return (0);
}

void	*ft_strset(int c, size_t len)
{
	char *s;

	s = ft_strnew(len);
	while (len > 0)
	{
		len--;
		s[len] = c;
	}
	return (s);
}

int		ft_len_int(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	init_flags(t_flags *f)
{
	f->u_used = 0;
	f->d_used = 0;
	f->champs = 0;
	f->negdot = 0;
	f->space = 0;
	f->prcnt = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->pad = 0;
	f->neg = 0;
	f->dot = 0;
	f->pre = 0;
	f->hh = 0;
	f->ll = 0;
	f->j = 0;
	f->z = 0;
	f->l = 0;
	f->h = 0;
}
