/*
** ia.c for lemicp in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Mon Mar  2 15:19:53 2015 Giudici
** Last update Tue Mar  3 17:22:44 2015 Giudici
*/

#include "lemipc.h"

int	get_rand()
{
  return ((random() % 100) + 1);
}

void	init_pos(t_ia  *ia, t_map *map)
{
  do
    {
      ia->x = get_rand();
      ia->y = get_rand();
    } while (get_case(ia->x, ia->y, map) != 0);
}

void	init_ia(t_ia *ia, char team, t_map *map)
{
  ia->team = team;
  ia->status = IDLE;
  ia->key = ftok(getcwd(0,0), (int)team);
  init_pos(ia, map);
  printf("x : %d  - y : %d \n", ia->x, ia->y);
  change_case(ia->x, ia->y, map, team);
}
