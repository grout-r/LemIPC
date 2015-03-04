
#include "lemipc.h"

typedef struct	s_msg
{
  long	mtype;
  char	str[64];
}	t_msg;

void		war(t_map *map, t_ia *ia)
{
  key_t	lb_key;
  int	lb_id;
  t_msg	msg;

  lb_key = ftok(map->cwd, ia->team);
  printf("Key %d\n", lb_key);
  lb_id = msgget(lb_key, SHM_R | SHM_W);
   if (lb_id == -1)
    {
      lb_id = msgget(lb_key, IPC_CREAT | SHM_R | SHM_W);
      printf("MsgQ %d\n", lb_id);
      msgrcv(lb_id, &msg, sizeof(msg), 12, 0);
      printf("%s\n", msg.str);
    }
  else
    {
      bzero(&msg, sizeof(msg));
      msg.mtype = 12;
      sprintf(msg.str, "Coucou, tu veut voir ma bite ?");
      msgsnd(lb_id, &msg, sizeof(msg), 0);
      msgctl(lb_id, IPC_RMID, NULL);
    }
}
