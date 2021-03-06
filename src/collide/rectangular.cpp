// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Bibliothèque Lapin

#include		"lapin_private.h"

bool			bunny_rectangular_collision_dot(const t_bunny_accurate_area	*elem,
							const t_bunny_accurate_position	*pos)
{
  bool			res;

  res = pos->x >= elem->x && pos->x < elem->x + elem->w &&
    pos->y >= elem->y && pos->y < elem->y + elem->h;
  scream_log_if("%p area, %p dot -> %s", "collision", elem, pos, res ? "true" : "false");
  return (res);
}

bool			bunny_rectangular_collision(const t_bunny_accurate_area		*a,
						    const t_bunny_accurate_area		*b)
{
  bool			res;

  res = a->x < b->x + b->w && a->x + a->w > b->x &&
    a->y < b->y + b->h && a->y + a->h > b->y;
  scream_log_if("%p area, %p area -> %s", "collision", a, b, res ? "true" : "false");
  return (res);
}

