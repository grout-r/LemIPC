/*
** ia.h for lemipc in /home/giudici/rendu/lemipc/LemIPC
** 
** Made by Giudici
** Login   <giudici@epitech.net>
** 
** Started on  Mon Mar  2 15:16:59 2015 Giudici
** Last update Mon Mar  2 16:56:39 2015 Giudici
*/

#ifndef IA_H_
# define IA_H_

# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <stdio.h>

# define SURRENDER 0
# define IDLE	   1
# define WAR	   2

typedef struct	s_ia
{
  int		shm_id;
  key_t		key;
  char		team;
  char		status;
  int		x;
  int		y;
}		t_ia;

void	init_ia(t_ia *ia, char team);
int	get_rand();
void	gree_space(t_ia *ia, t_map *map);
void	init_ia(t_ia *ia, char team, t_map *map);

#endif /* IA_H_ */
