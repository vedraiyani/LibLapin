// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Lapin library

#include			"lapin_private.h"

bool				bunny_cipher_file(const char			*file,
						  t_bunny_ciphering		cip,
						  const t_bunny_cipher_key	*key)
{
  char				*cnt;
  size_t			len;
  bool				ret;

  if ((cnt = bunny_load_file(file, &len)) == NULL)
    return (false);
  bunny_cipher_data(cnt, len, cip, key);
  ret = bunny_save_file(file, cnt, len);
  bunny_free(cnt);
  return (ret);
}

