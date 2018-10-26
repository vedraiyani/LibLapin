/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2018
**
** Bibliotheque Lapin
*/

/*!
** \file box.h
**
*/

#ifndef				__LAPIN_BOX_H__
# define			__LAPIN_BOX_H__
# if				!defined(__LAPIN_H__)
#  error			You cannot include this file directly.
# endif

struct s_bunny_box_system;

typedef enum			e_bunny_box_type
  {
    BBT_SIMPLE_BOX,
    BBT_CUSTOM_BOX
  }				t_bunny_box_type;

extern const char		*gl_bunny_box_type[BBT_CUSTOM_BOX];

typedef struct			s_bunny_gui_box
{
  t_bunny_box_type		type;
  const char			*id;
  struct s_bunny_gui_box	*parent;
  t_bunny_configuration		*configuration;
  void				(*display)(struct s_bunny_box_system		*sys,
					   struct s_bunny_gui_box		*bos,
					   const t_bunny_accurate_position	*offset);
  void				(*destructor)(struct s_bunny_gui_box		*box);
  t_bunny_map			*children;
  t_bunny_accurate_position	position;
  t_bunny_accurate_size		size;
  t_bunny_color			color;
}				t_bunny_gui_box;

typedef t_bunny_gui_box		*(*t_bunny_new_box)(t_bunny_gui_box		*parent,
						    t_bunny_configuration	*cnf);

/*!
** ****************************************************************
** ************** HANGED BUNNY STUDIO GUI SYSTEM ******************
** ****************************************************************
**
** This context is the HBS GUI System. It brings graphic user interface
** object like windows, buttons and textbox.
**
** It is designed to be efficiently used with a subcontext in order
** to work as an overlay. Any other context should be able to be used
** as subcontext of this one as it is transitive (that means that event
** received by the current context that are not handled are transmitted
** to the subcontext - all context should act this way, but this one
** give you the guarantee that is is)
**
** Box events may be handled by Dabsic scripts.
** Box status are transmitted to a runtime configuration so it may
** be reached by Dabsic scripts.
** You may put your own data inside this runtime configuration
** so it could also be reached.
**
** What is the difference between head.subcontext and subcontext?
** The head.subcontext is useful to define specific handlers that
** will allow you to customize the GUI itself.
** The subcontext pointer allow the GUI to be used as an overlay
** of subcontext. Something that will be printed *over* it and
** that will transmist events.
*/
typedef struct			s_bunny_box_system
{
  t_bunny_context_runtime_info	head;
  t_bunny_context_runtime_info	*subcontext;
  t_bunny_gui_box		screen;

  const char			_private[512];
}				t_bunny_box_system;

extern const t_bunny_context	gl_bunny_box_context;
extern const t_bunny_new_box	gl_bunny_new_box[BBT_CUSTOM_BOX];
extern t_bunny_new_box		gl_bunny_custom_new_box;

t_bunny_configuration		*bunny_init_box_environ(int		width,
							int		height);

void				*bunny_new_gui_box(size_t		siz,
						   t_bunny_configuration*cnf);
bool				bunny_load_box(t_bunny_box_system	*bs,
					       const char		*file,
					       t_bunny_configuration	*env);
bool				bunny_read_box(t_bunny_box_system	*bs,
					       t_bunny_configuration	*cnf);

void				bunny_delete_box(t_bunny_gui_box	*box);

#endif	/*			__LAPIN_BOX_H__		*/