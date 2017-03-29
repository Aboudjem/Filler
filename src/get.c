
#include "filler.h"

void	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	get_size_map(map);
	map->map = (char **)malloc(sizeof(char *) * map->height + 1);
	get_next_line(0, &line);
	while (i < map->height)
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup(line + 4);
		//free(line);
		i++;
	}
	map->map[i] = NULL;
}

void	get_size_map(t_map *map)
{
	int		i;
	char	*line;

	i = 8;
	get_next_line(0, &line);
	if (ft_isdigit(line[i]) == 1)
	{
		map->height = ft_atoi(line + i);
		i += ft_len_int(map->height);
	}
	else
		exit (-1);
	map->width = ft_atoi(line + i);
	//free(line);
}

void	get_size_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 6;
	get_next_line(0, &line);
	if (ft_isdigit(line[i]) == 1)
	{
		piece->height = ft_atoi(line + i);
		i += ft_len_int(piece->height);
	}
	else
		exit (-1);
	piece->width = ft_atoi(line + i);
	//free(line);
}

void	get_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 0;
	get_size_piece(piece);
	piece->piece = (char **)(malloc(sizeof(char *) * piece->height + 1));
	while (i < piece->height)
	{
		get_next_line(0, &line);
		piece->piece[i] = ft_strdup(line);
		i++;
		//free(line);
	}
	piece->piece[i] = NULL;
}
