/*
** map.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 17:48:23 2015 Giudici
** Last update Fri Mar  6 16:41:50 2015 Giudici
*/

#include "lemipc.h"

void		change_case(t_pos *pos, t_map *map, char value)
{
  int		id;
  char		*tmp;

  id = map->head[pos->y];
  tmp = shmat(id, NULL, SHM_R | SHM_W);
  tmp[pos->x] = value;
}

char		get_case(t_pos *pos,  t_map *map)
{
  int		id;
  char		*tmp;

  id = map->head[pos->y];
  tmp = shmat(id, NULL, SHM_R | SHM_W);
  if (pos->x < 0 || pos->x > 100 || pos->y < 0 || pos->y > 100)
    return (-1);
  return (tmp[pos->x]);
}

void		dump_map(t_map *map)
{
  int		i;
  int		y;
  int		id;
  char		*tmp;

  i = 0;
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      y = 0;
      printf("%d\t: ", i);
      while (y != COL_NBR)
	printf("%c", tmp[y++] + 48);
      printf("\n");
      i++; 
    }
}

char		search_team(t_map *map)
{
  int		i;
  int		y;
  int		id;
  char		*tmp;

  i = 0;
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      y = 0;
      while (y != COL_NBR) {
        if (tmp[y] != '0') {
	  return (tmp[y]);
	}
	y = y + 1;
      }
      i = i + 1;
    }
  return ('0');
}

int		alone_in_the_dark(t_map *map)
{
  int		i;
  int		y;
  char		c;
  int		id;
  char		*tmp;

  i = 0;
  c = search_team(map);
  if (c == '0')
    return (1);
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      y = 0;
      while (y != COL_NBR) {
	if (tmp[y] != '0' && tmp[y] != c) {
	  return (0);
	}
        y = y + 1;
      }
      i = i + 1;
    }
  return (1);
}
