
#include "lemipc.h"

int		main()
{ 
  t_map		map;
  t_ia		ia;

  init_ia(&ia, 'a', &map);
  srand(time(NULL));
  parse_arg(&map);
  init(&map);
  return (0);
}
