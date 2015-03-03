
#include "lemipc.h"

int		main()
{ 
  t_map		map;
  t_ia		ia;

  init(&map);
  init_ia(&ia, 'a', &map);
  srand(time(NULL));
  parse_arg(&map);
  return (0);
}
