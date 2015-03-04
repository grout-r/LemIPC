
#include "lemipc.h"

void		change_case(int x, int y, t_map *map, char value)
{
  int		id;
  char		*tmp;

  id = map->head[y];
  tmp = shmat(id, NULL, SHM_R | SHM_W);
  tmp[x] = value;
}

char		get_case(t_pos *pos,  t_map *map)
{
  int		id;
  char		*tmp;

  id = map->head[pos->y];
  tmp = shmat(id, NULL, SHM_R | SHM_W);
  return (tmp[pos->x]);
}

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

void		dump_map(t_map *map)
{
  int		i;
  int		y;
  int		id;
  char		*tmp;

  i = 0;
  while (i != LIN_NBR)
    {
      id = map->head[i];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      y = 0;
      printf("%d     : ", i);
      while (y != COL_NBR)
	printf("%c", tmp[y++] + 48);
      printf("\n");
      i++; 
    }
}
