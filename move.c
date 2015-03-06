/*
** move.c for move in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Wed Mar  4 16:48:28 2015 Giudici
** Last update Fri Mar  6 17:12:05 2015 Giudici
*/

#include "lemipc.h"


int		move(t_ia *ia, t_map *map, int new_x, int new_y)
{
  t_refresh	pos;
  int		id_msg;

  bzero(&pos, sizeof(pos));
  pos.new_pos.x = new_x;
  pos.new_pos.y = new_y;
  if (get_case(&(pos.new_pos), map) == 0)
    return (-1);
  change_case(&(pos.new_pos), map, ia->team);
  pos.old_pos.x = ia->pos.x;
  pos.old_pos.y = ia->pos.y;
  pos.team = ia->team;
  change_case(&(pos.old_pos), map, '0');
  
  id_msg = msgget(ftok(getcwd(0,0), 42), SHM_R | SHM_W);
  if (id_msg == -1)  
    return (-1);
  msgsnd(id_msg, &pos, sizeof(pos), 0);
  //msgctl(id_msg, IPC_RMID, NULL);
  return (0);
}
