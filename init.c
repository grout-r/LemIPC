/*
** init.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Thu Mar  5 15:09:28 2015 Giudici
** Last update Thu Mar  5 16:32:02 2015 Giudici
*/
 
#include "lemipc.h"

void		first_init(t_map *map)
{
  int		i;
  key_t		cur_key;

  i = 1;
  printf("Created %d columns\n", LIN_NBR);
  map->head_id = shmget(map->head_key, sizeof(int) * LIN_NBR, IPC_CREAT | SHM_R | SHM_W);
  map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);
  while (i != LIN_NBR + 1)
    {
      cur_key = ftok(map->cwd, i);
      map->head[i - 1] = shmget(cur_key, sizeof(char) * COL_NBR, IPC_CREAT | SHM_R | SHM_W);
      memset(shmat(map->head[i - 1], NULL, SHM_R | SHM_W), 0, COL_NBR);
      i++;
    }
}

void		init_head(t_map *map)
{
  map->cwd = getcwd (0, 0);
  map->head_key = ftok(map->cwd, 0);
  map->head_id = shmget(map->head_key, sizeof(int) * COL_NBR, SHM_R | SHM_W);
}

void		init(t_map *map, t_ia *ia, int ac, char **av)
{
  init_head(map);
  if (map->head_id == -1)
    first_init(map);
  map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);      
  init_ia(ia, parse_arg(ac, av), map);
}

char		parse_arg(int ac, char **av)
{
  char		ret;

  if (ac == 1)
    return (random() % 10);
  ret = atoi(av[1]);
  if (ret < 0 || ret > 10)
    {
      puts("Team is not include between 0 and 10, set team random instead");
      return (random() % 10);
    }
  return (ret);
}

void		init_pos(t_ia *ia, t_pos *pos)
{
  pos->x = ia->pos.x;
  pos->y = ia->pos.y;
}
