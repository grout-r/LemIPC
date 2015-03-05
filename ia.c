/*
** ia.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 16:45:44 2015 Giudici
** Last update Thu Mar  5 16:55:06 2015 Giudici
*/

#include "lemipc.h"

int		war(t_pos *pos, t_map *map, t_ia *ia, t_msg  msg)
{
  if (msg_receive(&msg, ia) == -1)
    {
      ia->target_pos.x = 10;
      ia->target_pos.y = 12;
      while (ia->target_pos.x == -1)
	check_around(pos, map, ia);
      msg = construct_msg(ia->target_pos.x, ia->target_pos.y, (int)ia->team);
      if (create_msgq(ia) == -1)
	return (-1);
      if (msg_send(&msg, ia) == -1)
	return (-1);
    }
  else
    {
      if (msg_receive(&msg, ia) == -1)
	{
	  //traitement alternatif
	  printf("exit msg reiceive == -1\n");
	  return (0);
	}
      printf("%d = x || %d = y\n", ia->target_pos.x, ia->target_pos.y);
    }
  return (0);
}
