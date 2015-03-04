/*
** msgq.c for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Wed Mar  4 15:50:27 2015 Giudici
** Last update Wed Mar  4 16:45:44 2015 Giudici
*/

int		create_msgq(t_msg *msg, t_ia *ia)
{
  int		id_msg;

  id_msg = msgget(ia->key, IPC_CREAT | SHM_R | SHM_W);
  if (id_msg == -1)
    return (-1);
  return (0);
}

int		msg_receive(t_msg *msg, t_ia *ia)
{
  int		id_msg;

  id_msg = msgget(ia->key, SHM_R | SHM_W);
  if (id_msg == -1)
    return (-1);
  msgrcv(id_msg, &msg, sizeof(msg), 42, 0);
  return (0);
}

int		msg_send(t_msg *msg, t_ia *ia)
{
  int		id_msg;

  printf("%d\n", ia->key);
  id_msg = msgget(ia->key, SHM_R | SHM_W);
  if (id_msg == -1)
    return (-1);
  msgsnd(id_msg, &msg, sizeof(msg), 0);
  msgctl(id_msg, IPC_RMID, NULL);
  return (0);
}

t_msg		construct_msg(int x, int y, int type)
{
  t_msg         msg;

  bzero(&msg, sizeof(msg));
  msg.pos.y = x;
  msg.pos.y = y;
  msg.mtype = type;
  return (msg);
}
