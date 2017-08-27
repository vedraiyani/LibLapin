// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Lapin library

#include		"lapin_private.h"

static const char	*bunny_errors[LAST_ERROR - EHWPOISON] =
  {
    "Cannot generate dynamic ressource",
    "Syntax error encountered while reading code",
    "Container is empty and cannot supply any value",
    "Duplication of the stored element failed.",
    "Cannot find requested element",
    "No embedded key found. The program was not made with LibLapin or its key is already prepared.",
    "No display device specified in environment"
  };

const char		*bunny_strerror(int		errorid)
{
  if (errorid <= EHWPOISON)
    return (strerror(errorid));
  return (bunny_errors[errorid - EHWPOISON]);
}
