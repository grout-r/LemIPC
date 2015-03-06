
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lemipc.h"

typedef struct	s_gui
{
  SDL_Surface	*screen;
  int		*color;
}		t_gui;

typedef struct	s_rgb
{
  int		r;
  int		g;
  int		b;
}		t_rgb;

int		init_gui(t_gui *gui, int *color)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Erreur dans le chargement de la SDL %s\n", SDL_GetError());
      return (-1);
    }
  gui->screen =  SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);
  if (gui->screen == NULL)
    {
      puts("Error");
      return (-1);
    }
  SDL_WM_SetCaption("This is WAAAAAAR", NULL);
  SDL_FillRect(gui->screen, NULL, SDL_MapRGB(gui->screen->format, 0, 0, 0));
  SDL_Flip(gui->screen);
  gui->color = color;
  return (0);
}

t_rgb		color_converter(int hex)
{
  t_rgb		rgb;

  rgb.r = ((hex >> 16) & 0xFF);
  rgb.g = ((hex >> 8) & 0xFF);
  rgb.b = ((hex) & 0xFF);
  return (rgb); 
}

void		colorize_player(SDL_Surface *player, char team, t_gui *gui)
{
  t_rgb		rgb;

  rgb = color_converter(gui->color[(int)team]);
  SDL_FillRect(player, NULL, SDL_MapRGB(gui->screen->format, rgb.r, rgb.g, rgb.b));
}

void		init_color(int *color)
{
  color[0] = 0x000000;
  color[1] = 0x5958A3;
  color[2] = 0xE61732;
  color[3] = 0x17E6C0;
  color[4] = 0x40E617;
  color[5] = 0xE5FF00;
  color[6] = 0xFF00D0;
  color[7] = 0xFF4800;
  color[8] = 0x00FFAA;
  color[9] = 0x001EFF;
}

void		load_player(int x, int y, char team,  t_gui *gui)
{
  SDL_Surface	*player;
  SDL_Rect	pos;

  pos.x = x * 10;
  pos.y = y * 10;
  player = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  colorize_player(player, team, gui);
  SDL_BlitSurface(player, NULL, gui->screen, &pos);
  SDL_Flip(gui->screen);
}

int		dump_map_gui(t_gui *gui)
{

  key_t		msgkey;
  int		msgid;
  t_refresh	ref;

  msgkey = ftok(getcwd(0, 0), 42);
  msgid = msgget(msgkey, SHM_R | SHM_W);
  puts("42");
  if (msgid == -1)
    {
      msgid = msgget(msgkey, IPC_CREAT | SHM_R | SHM_W);
      puts("a");
      msgrcv(msgid, &ref, sizeof(ref), 42, 0);
      puts("b");
      load_player(ref.old_pos.x, ref.old_pos.y, 0, gui);
      load_player(ref.new_pos.x, ref.new_pos.y, ref.team, gui);
      printf("old = %d --- %d || new = %d --- %d || team %c \n", ref.old_pos.x, ref.old_pos.y, ref.new_pos.x, ref.new_pos.y, ref.team);
      puts("c");
      return (0);
    }
  puts("d");
  msgrcv(msgid, &ref, sizeof(ref), 0, 0);
  putchar('e');
  printf("old = %d --- %d || new = %d --- %d || team %c \n", ref.old_pos.x, ref.old_pos.y, ref.new_pos.x, ref.new_pos.y, ref.team);
  load_player(ref.old_pos.x, ref.old_pos.y, 0, gui);
  load_player(ref.new_pos.x, ref.new_pos.y, ref.team, gui);
  return (0);
}

int		main()
{ 
  t_gui		gui;
  int		color[10];
  SDL_Event	event;

  init_color(color);
  if (init_gui(&gui, color) == -1)
    return (-1);
  SDL_PollEvent(&event);
  while(event.type != SDL_QUIT)
    {
      SDL_PollEvent(&event);
      dump_map_gui(&gui);
    }
  return 0;
}
