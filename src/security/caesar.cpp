// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin library

#include			"lapin_private.h"

void				__bunny_caesar(char			*cnt,
					       size_t			len,
					       const t_bunny_cipher_key	*key,
					       bool			cipher)
{
  size_t			i;

  if (cipher)
    for (i = 0; i < len; ++i)
      cnt[i] += key->key[i % key->length];
  else
    for (i = 0; i < len; ++i)
      cnt[i] -= key->key[i % key->length];
}

