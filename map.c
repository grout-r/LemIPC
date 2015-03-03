
#include "lemipc.h"

char		get_case(int x, int y, t_map *map)
{
      int id;
      char *tmp;
      id = map->head[y];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      return (tmp[x]);
}
