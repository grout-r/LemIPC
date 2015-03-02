
#include "lemipc.h"

void		first_init(t_map *map)
{
  int		i;

  i = 0;
  map->shm_id = shmget(map->key, sizeof(int) * COL_NBR, IPC_CREAT | SHM_R | SHM_W);
  printf("Created %d columns\n", COL_NBR);

  map->head = shmat(map->shm_id, NULL, SHM_R | SHM_W);
  while (i != LIN_NBR)
    {
      i++;
    }
}

void		init(t_map *map)
{
  map->shm_id = shmget(map->key, 42, SHM_R | SHM_W);
  if (map->shm_id == -1)
    {
      first_init(map);
    }
  else
    {
      printf("Using shared memory segment %d\n", map->shm_id);
      map->head = shmat(map->shm_id, NULL, SHM_R | SHM_W);
      printf("Reading message from shared memory : %s\n", (char *)(map->head));
      shmctl(map->shm_id, IPC_RMID, NULL);
    }
}

key_t		parse_arg(int ac, char **av)
{
  key_t		key;
  if (ac != 2)
    {
      puts("Usage : ./lemipc pathname");
      return (-1);
    }
  key = ftok(av[1], 0);
  printf("I created a key for shared memory : %d\n", key);
  if (key == -1)
  {
    puts("Error on creating key, check your pathname");
    return (-1);
  }
  return (key);
}
