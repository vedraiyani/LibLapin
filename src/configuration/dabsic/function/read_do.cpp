// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin library

#include		"lapin_private.h"

Decision		dabsic_read_do(const char	*code,
				       ssize_t		&i,
				       Function		&func,
				       SmallConf	&funcnode,
				       SmallConf	&root)
{
  dabsic_read_separator(code, i);
  if (dabsic_read_inside_function(code, i, &func, funcnode, root) == BD_ERROR)
    return (BD_ERROR);
  dabsic_read_separator(code, i);
  if (readtextcase(code, i, "AgainIf"))
    {
      dabsic_read_separator(code, i);
      if (dabsic_read_instruction(code, i, func, funcnode, root) == BD_ERROR)
	scream_error_if
	  (return (BD_ERROR), BE_SYNTAX_ERROR,
	   "A value or expression was expected after 'againif' on line %s:%d",
	   "ressource,configuration,syntax",
	   SmallConf::file_read.top().c_str(), whichline(code, i)
	   );
      return (BD_OK);
    }
  scream_error_if
    (return (BD_ERROR), BE_SYNTAX_ERROR,
     "AgainIf was expected on line %s:%d",
     "ressource,configuration,syntax",
     SmallConf::file_read.top().c_str(), whichline(code, i)
     );
  return (BD_ERROR);
}

