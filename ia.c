#include "lemipc.h"

int		msg(t_msg *msg, t_ia *ia)
{
  int		id_msg;

  printf("%d\n", ia->key);
  id_msg = msgget(ia->key, SHM_R | SHM_W);
  printf("%d\n", id_msg);
  if (id_msg == -1)
    {
      id_msg = msgget(ia->key, IPC_CREAT | SHM_R | SHM_W);
      printf("create msgq %d\n", msgget(ia->key, IPC_CREAT | SHM_R | SHM_W));
      msgrcv(id_msg, &msg, sizeof(msg), 42, 0);
    }
  else
    {
      bzero(&msg, sizeof(msg));
      msgsnd(id_msg, &msg, sizeof(msg), 0);
      msgctl(id_msg, IPC_RMID, NULL);
    }
  return (0);
}

t_msg	construct_msg(int x, int y, int type)
{
  t_msg		msg;

  msg.pos.y = x;
  msg.pos.y = y; 
  msg.mtype = type;
  return (msg);
}

void		war(t_map *map, t_ia *ia)
{
  if (map == NULL)
    puts("lel");
  if (ia == NULL)
    puts("lel");
  //  while (42);
}
