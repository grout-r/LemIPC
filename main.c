
#include "lemipc.h"

int		main()
{ 
  t_map		map;
  t_ia		ia;

  srand(time(NULL));
  parse_arg(&map);
  init(&map);
  init_ia(&ia, 6, &map);
  war(&map, &ia);
  dump_map(&map);
  return (0);
}
