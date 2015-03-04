#include "lemipc.h"


int	msg(t_msg msg)
{
  int   id_msg;
  key_t key;
  t_msg msg;

  key = ftok(getcwd(0, 0), 10);
  printf("%d\n", key);
  id_msg = msgget(key, SHM_R | SHM_W);
  printf("%d\n", id_msg);
  if (id_msg == -1)
    {
      id_msg = msgget(key, IPC_CREAT | SHM_R | SHM_W);
      printf("create msgq %d\n", msgget(key, IPC_CREAT | SHM_R | SHM_W));
      msgrcv(id_msg, &msg, sizeof(msg), 42, 0);
      printf("%s\n", msg.str);
    }
  else
    {
      printf("using msgq %d\n", id_msg);
      bzero(&msg, sizeof(msg));
      msg.mtype = 42;
      sprintf(msg.str, "HelloWord !");
      msgsnd(id_msg, &msg, sizeof(msg), 0);
      msgctl(id_msg, IPC_RMID, NULL);
    }
}

void	construct_msg(int x, int y, char *str, int type)
{
  
}

void		war(t_map *map, t_ia *ia)
{
  if (map == NULL)
    puts("lel");
  if (ia == NULL)
    puts("lel");
  //  while (42);
}
