// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Bibliotheque Lapin

#include		"lapin_private.h"

void			bunny_sound_stop(t_bunny_sound		*sound)
{
  enum _music_or_sound	*type = (enum _music_or_sound*)sound;

  *((bool*)&sound->pause) = false;
  *((bool*)&sound->playing) = false;
  if (*type == MIDI)
    {
      struct bunny_midi *mid = (struct bunny_midi*)sound;

      fluid_player_stop(mid->player);
    }
  else if (*type == MUSIC)
    {
      struct bunny_music *snd = (struct bunny_music*)sound;

      snd->music.setPlayingOffset(sf::Time::Zero);
      snd->music.stop();
    }
  else
    ((struct bunny_effect*)sound)->sound.stop();
  scream_log_if("%p", "ressource,sound", sound);
}

