
#include "lemipc.h"

t_pos		*incr_x(t_scan *scan)
{
  while (scan->tmp->x != scan->pos->x + (scan->segment - 1))
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team)
	return (scan->tmp);
      scan->tmp->x++;
    }
  return (NULL);
}

t_pos		*incr_y(t_scan *scan)
{
  while (scan->tmp->y != scan->pos-> + (scan->segment - 1))
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team)
	return (scan->tmp);
      scan->tmp->y++;
    }
  return (NULL);
}

t_pos		*decr_x(t_scan *scan)
{
  while (scan->tmp->x != scan->pos->x)
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team)
	return (scan->tmp);
      scan->tmp->x--;
    }
  return (NULL);
}

t_pos		*decr_y(t_scan *scan)
{
  while (scan->tmp->y != scan->pos->y)
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team)
	return (scan->tmp);
      scan->tmp->y--;
    }
  return (NULL);
}

t_pos		*check_around(t_pos *pos, t_map *map, t_ia *ia)
{
  t_pos		tmp;
  t_scan	scan;
  
  scan->tmp = &tmp;
  scan->pos = pos;
  scan->ia = ia;
  scan->ap = map;
  scan->segment = 3
  if (get_case(pos, map) != 0 && get_case(pos, map) != ia->team)
    return (pos);
  scan->pos->x--;
  scan->pos->y--;
  while (scan->segment < 10)
    {
      tmp->x = pos->x;
      tmp->y = pos->y;
      incr_x(scan);
      incr_y(scan);
      decr_c(scan);
      decr_y(scan);
      scan->segment += 2;
      scan->pos->x--;
      scan->pos->y--;
    }
}
