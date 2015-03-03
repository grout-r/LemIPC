
#include "lemipc.h"

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
  int		id;
  char		*tmp;

  i = 0;
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      i++;
      if(tmp == NULL)
	puts("l");
    }
}
