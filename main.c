/*
** main.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 16:41:04 2015 Giudici
** Last update Thu Mar  5 16:41:05 2015 Giudici
*/

#include "lemipc.h"

int		main(int ac, char **av)
{ 
  t_map		map;
  t_ia		ia;
  t_msg		msg;
  t_pos		pos;

  srand(time(NULL));
  init(&map, &ia, ac, av);
  dump_map(&map);
  //traitement
  //while (alone_in_the_dark() == -1)
  init_pos(&ia, &pos);
  war(&pos, &map, &ia, msg);
  //shmctl(map.head_id, IPC_RMID, NULL);
  return (0);
}
