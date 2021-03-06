// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Biblithèque Lapin

#include			"lapin_private.h"

void				bunny_set_mouse_visibility(const t_bunny_window	*_win,
							   bool			visible)
{
  const struct bunny_window	*win = (const struct bunny_window*)_win;

  win->window->setMouseCursorVisible(visible);
  scream_log_if("%p window, %s visible", "system,window", win, visible ? "true" : "false");
}

