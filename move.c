/*
** move.c for move in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Wed Mar  4 16:48:28 2015 Giudici
** Last update Thu Mar  5 20:44:43 2015 Giudici
*/

#include "lemipc.h"

int		move(t_ia *ia, t_map *map, int new_x, int new_y)
{
  t_pos		pos;

  pos.x = ia->pos.x;
  pos.y = ia->pos.y;
  change_case(&pos, map, '0');
  pos.x = new_x;
  pos.y = new_y;
  if (get_case(&pos, map) == 0)
    return (-1);
  change_case(&pos, map, ia->team);
  return (0);
}
