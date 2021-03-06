/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
** LibLapin - Handle events
*/

#include		<stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */
#include		<stdio.h> /* printf */
#include		<lapin.h>

typedef struct		s_program
{
  char			*name;
  t_bunny_window	*win;
}			t_program;

static const char	*state_str(t_bunny_event_state		state)
{
  /* A key that was released has been pressed (lapin/events.h) */
  if (state == GO_DOWN)
    return ("pressed");
  return ("released");
}

t_bunny_response	key_response(t_bunny_event_state	state,
				     t_bunny_keysym		sym,
				     void			*data)
{
  char			**str = data;

  printf("%s: The key n°=%d is %s.\n", *str, sym, state_str(state));
  /* A key that was pressed has been released. The key was escape. (lapin/events.h) */
  if (state == GO_UP && sym == BKS_ESCAPE)
    {
      printf("%s: Closing the window with escape.\n", *str);
      /* Say we want to exit bunny_loop* and that the program is a success (lapin/events.h) */
      return (EXIT_ON_SUCCESS);
    }
  /* Say we want to stay in bunny_loop* (lapin/events.h) */
  return (GO_ON);
}

t_bunny_response	click_response(t_bunny_event_state	state,
				       t_bunny_mouse_button	button,
				       void			*data)
{
  t_program		*prog = data;

  printf("%s: The button n°=%d is %s.\n", prog->name, button, state_str(state));
  /* A mouse button that was pressed has been released. The button was the left one on the mouse (lapin/events.h) */
  if (button == BMB_LEFT && state == GO_UP)
    /* clear the content of the window with a random non transparent color */
    /* bunny_clear takes a t_bunny_buffer. Because a window contains a t_bunny_buffer, */
    /* you can use it with t_bunny_window this way */
    /* The second parameter is the color */
    /* (lapin/graphics.h, lapin/color.h) */
    bunny_clear(&prog->win->buffer, rand() | BLACK);
  /* Say we want to stay in bunny_loop* (lapin/events.h) */
  return (GO_ON);
}

t_bunny_response	main_loop(void				*data)
{
  t_program		*prog = data;

  /* compute every drawing made on the window and display it on screen */
  /* the parameter is the window to refresh */
  /* if you do not do this, the window content will remain undefined */
  /* (lapin/window.h) */
  bunny_display(prog->win);
  /* Say we want to stay in bunny_loop* (lapin/events.h) */
  return (GO_ON);
}

int			main(int				argc,
			     char				**argv)
{
  t_program		program;

  (void)argc; /* we will not use the argc parameter */
  
  /* open a window */
  /* width on window, height of window, fullscreen? true, or false, name of the window */
  program.win = bunny_start(800, 600, false, "LibLapin - Events");
  if (program.win == NULL)
    {
      bunny_printlerr("Cannot open the window."); /* print litteral on stderr (lapin/misc.h) */
      return (EXIT_FAILURE);
    }
  program.name = argv[0];

  /* clear the content of the window with PINK2 color */
  /* bunny_clear takes a t_bunny_buffer. Because a window contains a t_bunny_buffer, */
  /* you can use it with t_bunny_window this way */
  /* The second parameter is the color */
  /* (lapin/graphics.h, lapin/color.h) */
  bunny_clear(&program.win->buffer, PINK2);
  
  bunny_printl("Press escape to exit. Click left to change the window color."); /* print litteral on stdout (lapin/misc.h) */

  /* set functions that will be called if event of specific types happened */
  /* keydown or keyup, clickdown or clickup, time passes  */
  bunny_set_key_response(key_response); /* lapin/events.h */
  bunny_set_click_response(click_response); /* lapin/events.h */
  bunny_set_loop_main_function(main_loop); /* lapin/events.h */
    
  /* loop until until the exit button is pushed */
  /* The first parameter is the window, the second the number of frame per seconds */
  /* Also manage events by calling function given previously with bunny_set_*_response */
  /* functions and bunny_set_loop_main_function. */
  /* The third parameter is sent to these functions */
  /* (lapin/events.h) */
  bunny_loop(program.win, 25, &program);

  /* destroy the window (lapin/window.h) */
  bunny_stop(program.win);
  return (EXIT_SUCCESS);
}

