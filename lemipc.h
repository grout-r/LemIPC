
#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define COL_NBR 100
# define LIN_NBR 100
# define SURRENDER 0
# define IDLE	   1
# define WAR	   2

typedef struct		s_map
{
  int			*head;
  int			head_id;
  key_t			head_key;
  char			*cwd;
}			t_map;

typedef struct	s_ia
{
  int		shm_id;
  key_t		key;
  char		team;
  char		status;
  int		x;
  int		y;
}		t_ia;

void		first_init(t_map *map);
void		init(t_map *map);
int		parse_arg(t_map *map);
void		init_head(t_map *map);
char		get_case(int x, int y, t_map *map);
int		get_rand();
void		gree_space(t_ia *ia, t_map *map);
void		init_ia(t_ia *ia, char team, t_map *map);

#endif
