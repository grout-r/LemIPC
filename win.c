/*
** win.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 20:24:45 2015 Giudici
** Last update Thu Mar  5 20:35:34 2015 Giudici
*/

#include "lemipc.h"

char		who_win(t_map *map)
{
  int           i;
  int           y;
  int           id;
  char          *tmp;

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
  return (-1);
}
