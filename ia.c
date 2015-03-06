/*
** ia.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 16:45:44 2015 Giudici
** Last update Fri Mar  6 16:41:10 2015 Giudici
*/

#include "lemipc.h"

int		get_next_pos(int coord, int new_coord)
{
  int	result;

  result = coord - new_coord;
  if (result < 0)
    return (coord + 1);
  else if (result > 0)
    return (coord - 1);
  else
    return (coord);
}

int		go_to_the_target(t_map *map, t_ia *ia)
{
  t_pos		pos;

  while (ia->pos.x != ia->target_pos.x || ia->pos.y != ia->target_pos.y)
    {
      pos.x = get_next_pos(ia->pos.x, ia->target_pos.x);
      pos.y = get_next_pos(ia->pos.y, ia->target_pos.y);
      ia->pos.x = pos.x;
      ia->pos.y = pos.y;
      move(ia, map, pos.x, pos.y);
      //pos.x = ia->target_pos.x;
      //pos.y = ia->target_pos.y;
      //if (check_around(&pos, map, ia) == -1)
      //return (-1);
      printf("to target x: %d  ===you===> %d || to target y: %d ===you===> %d\n", ia->target_pos.x, ia->pos.x, ia->target_pos.y, ia->pos.y);
    }
  return (0);
}

int		war(t_pos *pos, t_map *map, t_ia *ia, t_msg  msg)
{
  if (msgget(ia->key, SHM_R | SHM_W) == -1)
    {
      printf("First process of my team, creating mailbox ...\n");
      if (create_msgq(ia) == -1)
	return (-1);
      msg_receive(&msg, ia);
      printf("%d = x || %d = y\n", ia->target_pos.x, ia->target_pos.y);
      go_to_the_target(map, ia);
    }
  else
    {
      printf("entre ici si t'es deuxième\n");
      if (check_around(pos, map, ia, 50) == -1) {
	printf("%d = x || %d = y\n", ia->target_pos.x, ia->target_pos.y);
	return (-1);
      }
      printf("%d = x || %d = y\n", ia->target_pos.x, ia->target_pos.y);
      msg = construct_msg(ia->target_pos.x, ia->target_pos.y, (int)ia->team);
      if (msg_send(&msg, ia) == -1)
        return (-1);
      go_to_the_target(map, ia);
    }
  return (0);
}
