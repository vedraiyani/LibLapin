// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2018
//
// Lapin Library

#include		"lapin_private.h"

#define			PATTERN		"%s -> %p"

t_bunny_pixelarray	*bunny_load_pixelarray(const char		*file)
{
  struct bunny_pixelarray	*pa;
  uint64_t			hash;

  if (bunny_which_format(file) != BC_CUSTOM)
    {
      t_bunny_pixelarray	*px;

      if (bunny_set_clipable_attribute(file, (t_bunny_picture**)&px, NULL, BCT_PIXELARRAY) == false)
	return (NULL);
      return (px);
    }
  hash = bunny_hash(BH_FNV, file, strlen(file));

  if (gl_bunny_ressource_ciphering)
    {
      void		*data;
      size_t		siz;

      if (bunny_load_file(file, &data, &siz) == -1)
	return (NULL);
      gl_bunny_ressource_ciphering((char*)data, siz, gl_bunny_ressource_data, false);
      if ((pa = (struct bunny_pixelarray*)
	   bunny_read_pixelarray_id(data, siz, file)) == NULL)
	return (NULL);
      bunny_delete_file(data, file);
      return ((t_bunny_pixelarray*)pa);
    }

  if ((pa = new (std::nothrow) struct bunny_pixelarray) == NULL)
    goto ReturnNull;
  if ((pa->sprite = new (std::nothrow) sf::Sprite) == NULL)
    goto DeleteStructure;
  if (RessourceManager.disable_manager ||
      (pa->tex = (sf::Texture*)RessourceManager.TryGet(ResManager::SF_TEXTURE, hash)) == NULL)
    {
      if ((pa->tex = new (std::nothrow) sf::Texture) == NULL)
	goto DeleteSprite;
      if (pa->tex->loadFromFile(file) == false)
	goto DeleteTexture;
      if ((pa->rawpixels =
	   (unsigned int*)bunny_malloc(pa->tex->getSize().x * pa->tex->getSize().y * sizeof(*pa->rawpixels))) == NULL)
	goto DeleteTexture;
      if ((pa->image = new (std::nothrow) sf::Image) == NULL)
	goto DeleteRawPixels;
      try
	{
	  *pa->image = pa->tex->copyToImage();
	}
      catch (...)
	{}
      if (pa->image->getSize() != pa->tex->getSize())
	goto DeleteImage;
      memcpy(pa->rawpixels, pa->image->getPixelsPtr(),
	     pa->tex->getSize().x * pa->tex->getSize().y * sizeof(*pa->rawpixels));
    }
  else
    {
      pa->image = (sf::Image*)RessourceManager.TryGet(ResManager::SF_IMAGE, hash);
      pa->tex = (sf::Texture*)RessourceManager.TryGet(ResManager::SF_TEXTURE, hash);
      pa->rawpixels = (unsigned int*)RessourceManager.TryGet(ResManager::BUNNY_PIXELS, hash);
    }

  if (RessourceManager.disable_manager == false)
    {
      RessourceManager.AddToPool(ResManager::SF_IMAGE, file, hash, pa, pa->image);
      RessourceManager.AddToPool(ResManager::SF_TEXTURE, file, hash, pa, pa->tex);
      RessourceManager.AddToPool(ResManager::BUNNY_PIXELS, file, hash, pa, pa->rawpixels);
    }

  pa->res_id = hash;
  pa->sprite->setTexture(*pa->tex);

  pa->type = SYSTEM_RAM;
  pa->width = pa->tex->getSize().x;
  pa->height = pa->tex->getSize().y;

  pa->rect.x = 0;
  pa->rect.y = 0;
  pa->rect.w = pa->width;
  pa->rect.h = pa->height;
  pa->position.x = 0;
  pa->position.y = 0;
  pa->origin.x = 0;
  pa->origin.y = 0;
  pa->scale.x = 1;
  pa->scale.y = 1;
  pa->rotation = 0;
  pa->color_mask.full = WHITE;

  scream_log_if(PATTERN, "ressource,graphics", file, pa);
  return ((t_bunny_pixelarray*)pa);

 DeleteImage:
  delete pa->image;
 DeleteRawPixels:
  bunny_free(pa->rawpixels);
 DeleteTexture:
  delete pa->tex;
 DeleteSprite:
  delete pa->sprite;
 DeleteStructure:
  delete pa;
 ReturnNull:
  scream_error_if(return (NULL), ENOMEM, PATTERN, "ressource,graphics", file, pa);
  return (NULL);
}

