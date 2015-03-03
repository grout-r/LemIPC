
#include "lemipc.h"

void		change_case(int x, int y, t_map *map, char value)
{
      int id;
      char *tmp;
      id = map->head[y];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      tmp[x] = value;
}

char		get_case(int x, int y, t_map *map)
{
      int id;
      char *tmp;
      id = map->head[y];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      return (tmp[x]);
}

void		dump_map(t_map *map)
{
  int		i;
  int		y;
  int		id;
  char		*tmp;

  i = 0;
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      y = 0;
      printf("%d     : ", i);
      while (y != COL_NBR)
	printf("%c", tmp[y++] + 48);
      printf("\n");
      i++; 
    }
}
