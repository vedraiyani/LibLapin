// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin library

#include		"lapin_private.h"

#define			PATTERN			\
  "%p picture, %p (%d, %d -> %d, %d -> %d, %d) position, %p (%p -> %p -> %p) color"

void			bunny_set_polygon(t_bunny_buffer		*buffer,
					  const t_bunny_position	*position,
					  const unsigned int		*color)
{
  size_t		*type = (size_t*)buffer;
  sf::Vertex		vert[3] =
    {
      sf::Vertex
      (sf::Vector2f(position[0].x, position[0].y),
       sf::Color
       ((color[0] >> (RED_CMP * 8)) & 0xFF,
	(color[0] >> (GREEN_CMP * 8)) & 0xFF,
	(color[0] >> (BLUE_CMP * 8)) & 0xFF,
	(color[0] >> (ALPHA_CMP * 8)) & 0xFF
	)
       ),
      sf::Vertex
      (sf::Vector2f(position[1].x, position[1].y),
       sf::Color
       ((color[1] >> (RED_CMP * 8)) & 0xFF,
	(color[1] >> (GREEN_CMP * 8)) & 0xFF,
	(color[1] >> (BLUE_CMP * 8)) & 0xFF,
	(color[1] >> (ALPHA_CMP * 8)) & 0xFF
	)
       ),
      sf::Vertex
      (sf::Vector2f(position[2].x, position[2].y),
       sf::Color
       ((color[2] >> (RED_CMP * 8)) & 0xFF,
	(color[2] >> (GREEN_CMP * 8)) & 0xFF,
	(color[2] >> (BLUE_CMP * 8)) & 0xFF,
	(color[2] >> (ALPHA_CMP * 8)) & 0xFF
	)
	)
    };
  switch (*type)
    {
    case WINDOW:
      {
	struct bunny_window	*pic = (struct bunny_window*)buffer;

	pic->window->draw(vert, 3, sf::Triangles);
	scream_log_if
	  (PATTERN, "graphics", buffer, position,
	   position[0].x, position[0].y,
	   position[1].x, position[1].y,
	   position[2].x, position[2].y,
	   color, (void*)(size_t)color[0], (void*)(size_t)color[1], (void*)(size_t)color[2]);
	return ;
      }
    case DRESSED_SPRITE:
    case SPRITE:
    case TTF_TEXT:
    case GRAPHIC_TEXT:
    case GRAPHIC_RAM:
      {
	struct bunny_picture	*pic = (struct bunny_picture*)buffer;

	if (pic->res_id != 0)
	  bunny_make_clipable_unique((t_bunny_clipable*)buffer);
	pic->texture->draw(vert, 3, sf::Triangles);
	scream_log_if
	  (PATTERN, "graphics", buffer, position,
	   position[0].x, position[0].y,
	   position[1].x, position[1].y,
	   position[2].x, position[2].y,
	   color, (void*)(size_t)color[0], (void*)(size_t)color[1], (void*)(size_t)color[2]);
	return ;
      }
    case SYSTEM_RAM:
      {
	struct bunny_pixelarray	*pix = (struct bunny_pixelarray*)buffer;

	if (gl_bunny_my_set_polygon == NULL)
	  fprintf(stderr, "gl_bunny_my_set_polygon is not set.\n");
	else
	  {
	    if (pix->res_id != 0)
	      bunny_make_clipable_unique((t_bunny_clipable*)buffer);
	    gl_bunny_my_set_polygon((t_bunny_pixelarray*)pix, position, color);
	  }
	scream_log_if
	  (PATTERN, "graphics", buffer, position,
	   position[0].x, position[0].y,
	   position[1].x, position[1].y,
	   position[2].x, position[2].y,
	   color, (void*)(size_t)color[0], (void*)(size_t)color[1], (void*)(size_t)color[2]);
	return ;
      }
    default:
      scream_error_if
	(return, EINVAL, PATTERN, "graphics", buffer, position,
	 position[0].x, position[0].y,
	 position[1].x, position[1].y,
	 position[2].x, position[2].y,
	 color, (void*)(size_t)color[0], (void*)(size_t)color[1], (void*)(size_t)color[2]);

    }
}
