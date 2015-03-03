 
#include "lemipc.h"

void		first_init(t_map *map)
{
  int		i;
  key_t		cur_key;

  i = 1;
  printf("Created %d columns\n", LIN_NBR);
  map->head_id = shmget(map->head_key, sizeof(int) * COL_NBR, IPC_CREAT | SHM_R | SHM_W);
  map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);
  while (i != LIN_NBR + 1)
    {
      cur_key = ftok(map->cwd, i);
      map->head[i - 1] = shmget(cur_key, sizeof(char) * COL_NBR, IPC_CREAT | SHM_R | SHM_W);
      i++;
    }
}

void		init_head(t_map *map)
{
  map->cwd = getcwd (0, 0);
  map->head_key = ftok(map->cwd, 0);
  map->head_id = shmget(map->head_key, sizeof(int) * COL_NBR, SHM_R | SHM_W);
}

void		init(t_map *map)
{
  init_head(map);
  if (map->head_id == -1)
      first_init(map);
  else
    {
      map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);      
      puts("else");
      printf("%c\n", get_case(12, 4, map));
      shmctl(map->head_id, IPC_RMID, NULL);
    }
}

int		parse_arg(t_map *map)
{
  return (map->head_id);
}
