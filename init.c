
#include "lemipc.h"

void		first_init(t_map *map)
{
  int		i;
  key_t		cur_key;

  i = 1;
  printf("Created %d columns\n", COL_NBR);
  map->head_id = shmget(map->head_key, sizeof(int) * COL_NBR, IPC_CREAT | SHM_R | SHM_W);
  map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);
  while (i != COL_NBR + 1)
    {
      cur_key = ftok(map->cwd, i);
      map->head[i - 1] = shmget(cur_key, sizeof(char) * LIN_NBR, IPC_CREAT | SHM_R | SHM_W);
      i++;
    }
}

char		getCase(int x, int y, t_map *map)
{
      int id;
      char *tmp;
      id = map->head[y];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      return (tmp[x]);
}

void		init(t_map *map)
{
  map->cwd = getcwd (0, 0);
  map->head_key = ftok(map->cwd, 0);
  map->head_id = shmget(map->head_key, sizeof(int) * COL_NBR, SHM_R | SHM_W);
  if (map->head_id == -1)
    {
      first_init(map);
      int id;
      char *tmp;
      id = map->head[4];
      tmp = shmat(id, NULL, SHM_R | SHM_W);
      tmp[12] = 'a';
      puts("put an 'a' in case 12 of 4 tht line");
    }
  else
    {
      map->head = shmat(map->head_id, NULL, SHM_R | SHM_W);      
      puts("else");
      printf("%c\n", getCase(12, 4, map));
      shmctl(map->head_id, IPC_RMID, NULL);
    }
}

int		parse_arg(t_map *map)
{
  return (map->head_id);
}
