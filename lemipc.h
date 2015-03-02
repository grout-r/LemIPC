
#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>

#define COL_NBR 100
#define LIN_NBR 100

typedef struct		s_map
{
  void			*head;
  int			shm_id;
  key_t			key;
}			t_map;

void		first_init(t_map *map);
void		init(t_map *map);
key_t		parse_arg(int ac, char **av);

#endif
