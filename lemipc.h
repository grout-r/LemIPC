
#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <stdio.h>
# include <unistd.h>

#define COL_NBR 100
#define LIN_NBR 100

typedef struct		s_map
{
  int			*head;
  int			head_id;
  key_t			head_key;
  char			*cwd;
}			t_map;

void		first_init(t_map *map);
void		init(t_map *map);
int		parse_arg(t_map *map);

#endif
