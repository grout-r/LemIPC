
#include "lemipc.h"

int		main(int ac, char **av)
{ 
  t_map		map;		
  
  if ((map.key = parse_arg(ac, av)) == -1)
    return (-1);
  init(&map);
  return (0);
}
