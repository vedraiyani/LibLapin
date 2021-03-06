// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin library

#include		<sys/stat.h>
#include		"lapin_private.h"

bool			bunny_is_directory(const char		*file)
{
  struct stat		st;

  if (stat(file, &st) == false)
    return (false);
  return (S_ISREG(st.st_mode));
}

