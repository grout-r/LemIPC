#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <sys/msg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

# define COL_NBR 100
# define LIN_NBR 100
# define SURRENDER 0
# define IDLE   1
# define WAR   2

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_map
{
  int		*head;
  int		head_id;
  key_t		head_key;
  char		*cwd;
}		t_map;

typedef struct	s_ia
{
  int		shm_id;
  key_t		key;
  char		team;
  char		status;
  t_pos		pos;
  t_pos		target_pos;
}		t_ia;

typedef struct	s_msg
{
  long		mtype;
  t_pos		pos;
}		t_msg;

typedef struct	s_scan
{
  t_pos		*tmp;
  t_pos		*pos;
  t_ia		*ia;
  t_map		*map;
  int		segment;
}		t_scan;

void		first_init(t_map *map);
void		init(t_map *map, t_ia *ia, int ac, char **av);
char		parse_arg(int ac, char **av);
void		init_head(t_map *map);
char		get_case(t_pos *pos,  t_map *map);
int		get_rand();
void		init_pos(t_ia *ia, t_map *map);
void		init_ia(t_ia *ia, char team, t_map *map);
void		dump_map(t_map *map);
void		change_case(t_pos *pos, t_map *map, char value);
void		war(t_map *map, t_ia *ia);

#endif	/* LEMIPC_H_ */
