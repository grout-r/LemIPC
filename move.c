/*
** move.c for move in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Wed Mar  4 16:48:28 2015 Giudici
** Last update Fri Mar  6 15:39:09 2015 Giudici
*/

#include "lemipc.h"

int		move(t_ia *ia, t_map *map, int new_x, int new_y)
{
  t_pos		pos;

  pos.x = new_x;
  pos.y = new_y;
  if (get_case(&pos, map) == 0)
    return (-1);
  change_case(&pos, map, ia->team);
  pos.x = ia->pos.x;
  pos.y = ia->pos.y;
  change_case(&pos, map, '0');
  return (0);
}
