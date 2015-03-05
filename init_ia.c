/*
** ia.c for lemicp in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Mon Mar  2 15:19:53 2015 Giudici
** Last update Thu Mar  5 16:55:38 2015 Giudici
*/

#include "lemipc.h"

int	get_rand()
{
  return ((random() % 100) + 1);
}

void	init_ia_pos(t_ia  *ia, t_map *map)
{
  do
    {
      ia->pos.x = get_rand();
      ia->pos.y = get_rand();
    } while (get_case(&(ia->pos), map) != 0);
}

void	init_ia(t_ia *ia, char team, t_map *map)
{
  ia->team = team;
  ia->status = IDLE;
  ia->key = ftok(getcwd(0,0), (int)team);
  init_ia_pos(ia, map);
  printf("x : %d  - y : %d \n", ia->pos.x, ia->pos.y);
  change_case(&(ia->pos), map, team);
  ia->target_pos.x = -1;
  ia->target_pos.y = -1;
}
