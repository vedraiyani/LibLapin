// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin library

#include		"lapin_private.h"

void			bunny_display(const t_bunny_window	*pic)
{
  struct bunny_window	*win = (struct bunny_window*)pic;

  win->window->display();
  scream_log_if("%p", "window,graphics", pic);
}

