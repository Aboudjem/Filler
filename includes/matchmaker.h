/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matchmaker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:37:20 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/30 19:40:35 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCHMAKE_H
# define MATCHMAKE_H

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "filler.h"

#define ESCAPE 27
#define COLOR_DARKBLUE 92
#define COLOR_GREY 100
#define COLOR_LIGHT_ORANGE_ 104
#define COLOR_ORANGE_ 110
#define COLOR_LIGHT_RED_ 116
#define COLOR_RED_ 122
#define COLOR_L_L_YELLOW_ 128
#define COLOR_L_YELLOW 60
#define COLOR_LIGHT_YELLOW_ 134
#define COLOR_YELLOW_ 140
#define COLOR_FULL_YELLOW_ 146
#define COLOR_PINK 156

typedef struct	s_print
{
	char	*p1;
	char	*p2;
	int		score_p1;
	int		score_p2;
}				t_print;

typedef struct	s_mapw
{
	char	*o;
	char	*x;
	char	*dot;
}				t_mapw;

# endif
