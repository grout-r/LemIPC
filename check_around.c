
#include "lemipc.h"

t_pos		*incr_x(t_scan *scan)
{
  while (scan->tmp->x != (scan->pos->x + (scan->segment - 1)))
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team
	  && get_case(scan->tmp, scan->map) != -1)
	return (scan->tmp);
      scan->tmp->x++;
    }
  return (NULL);
}

t_pos		*incr_y(t_scan *scan)
{
  while (scan->tmp->y != (scan->pos->y + (scan->segment - 1)))
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team 
	  && get_case(scan->tmp, scan->map) != -1)
	return (scan->tmp);
      scan->tmp->y++;
    }
  return (NULL);
}

t_pos		*decr_x(t_scan *scan)
{
  while (scan->tmp->x != scan->pos->x)
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team 
	  && get_case(scan->tmp, scan->map) != -1)
	return (scan->tmp);
      scan->tmp->x--;
    }
  return (NULL);
}

t_pos		*decr_y(t_scan *scan)
{
  while (scan->tmp->y != scan->pos->y)
    {
      if (get_case(scan->tmp, scan->map) != 0 && get_case(scan->tmp, scan->map) != scan->ia->team 
	  && get_case(scan->tmp, scan->map) != -1)
	return (scan->tmp);
      scan->tmp->y--;
    }
  return (NULL);
}

int		set_target(t_pos *pos, t_ia *ia)
{
  ia->target_pos.x = pos->x;
  ia->target_pos.y = pos->y;
  return (0);
}

int		check_around(t_pos *pos, t_map *map, t_ia *ia, int i)
{
  t_pos		tmp;
  t_scan	scan;
  t_pos		*ret;

  scan.tmp = &tmp;
  scan.pos = pos;
  scan.ia = ia;
  scan.map = map;
  scan.segment = 3;
  if (get_case(pos, map) != 0 && get_case(pos, map) != ia->team)
    return (set_target(pos, ia));
  scan.pos->x--;
  scan.pos->y--;
  while (scan.segment < ((i * 2) + 2))
    {
      tmp.x = pos->x;
      tmp.y = pos->y;
      if ((ret = incr_x(&scan)) != NULL)
	return (set_target(ret, ia));
      if ((ret = incr_y(&scan)) != NULL)
	return (set_target(ret, ia));
      if ((ret = decr_x(&scan)) != NULL)
	return (set_target(ret, ia));
      if ((ret = decr_y(&scan)) != NULL)
	return (set_target(ret, ia));
      scan.segment += 2;
      scan.pos->x--;
      scan.pos->y--;
    }
  return (-1);
}
