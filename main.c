
#include "lemipc.h"

int		main(int ac, char **av)
{ 
  t_map		map;
  t_ia		ia;

  srand(time(NULL));
  init(&map, &ia, ac, av);
  dump_map(&map);
  war(&map, &ia);
  //shmctl(map.head_id, IPC_RMID, NULL);
  return (0);
}
