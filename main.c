/*
** main.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 16:41:04 2015 Giudici
** Last update Fri Mar  6 16:43:24 2015 Giudici
*/

#include "lemipc.h"

int		main(int ac, char **av)
{ 
  t_map		map;
  t_ia		ia;
  t_msg		msg;
  t_pos		pos;

  if (ac != 2) {
    puts("Usage : ./lemipc team\nthe team is a number between 1 and 10");
    return (0);
  }
  srand(time(NULL));
  init(&map, &ia, ac, av);
  //traitement
  //while (alone_in_the_dark(map) == 1)
  init_pos(&ia, &pos);
  //dump_map(&map);
  printf("ia info : team = %d, target_pos = %d - %d\n", ia.team, ia.target_pos.x, ia.target_pos.y);
  //dump_map(&map);
  //dump_map(&map);
  war(&pos, &map, &ia, msg);
  //msg = msg;
  //free_msg();
  //shmctl(map.head_id, IPC_RMID, NULL);
  //dump_map(&map);
  return (0);
}
