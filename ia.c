/*
** ia.c for lemicp in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Mon Mar  2 15:19:53 2015 Giudici
** Last update Tue Mar  3 02:39:33 2015 Giudici
*/

#include <stdlib.h>
#include <time.h>
#include "ia.h"

int	get_rand()
{
  return ((rand() % 100) + 1);
}

void	free_space(t_ia  *ia, t_map *map)
{
  do
    {
      ia.x = get_rand();
      ia.y = get_rand();
    } while (get_case(ia.x, ia.y, map) == 0);
}

void	init_ia(t_ia *ia, char team, t_map *map)
{
  ia->status = IDLE;
  ia->team = team;
  free_space(ia);
}

int	main(int ac, char **av)
{
  t_ia	ia;

  srand(time(null));
  init_ia(&ia, av[1], map);
  return (0);
}
