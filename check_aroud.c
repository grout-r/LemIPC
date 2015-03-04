
#include "lemipc.h"

t_pos		check_around(t_pos *pos, t_map *map, t_ia *ia)
{
  t_pos		tmp;
  int		segment;

  if (get_case(pos, map) != 0 && get_case(pos, map) != ia->team)
    return (t_pos);
  pos->x--;
  pos->y--;
  segment = 3;    
  while (segment < 10)
    {
      tmp->x = pos->x;
      tmp->y = pos->y;
      while (tmp->x != pos->x + (segment - 1))
	{
	  if (get_case(tmp, map) != 0 && get_case(tmp, map) != ia->team)
	    return (tmp);
	  tmp->x++;
	}
      while (tmp->y != pos-> + (segment - 1))
	{
	  if (get_case(tmp, map) != 0 && get_case(tmp, map) != ia->team)
	    return (tmp);
	  tmp->y++;
	}
      while (tmp->x != pos->x)
	{
	  if (get_case(tmp, map) != 0 && get_case(tmp, map) != ia->team)
	    return (tmp);
	  tmp->x--;
	}
      while (tmp->y != pos-y)
	{
	  if (get_case(tmp, map) != 0 && get_case(tmp, map) != ia->team)
	    return (tmp);
	  tmp->y--;
	}
      segment += 2;
      pos->x--;
      pos->y--;
    }
}
