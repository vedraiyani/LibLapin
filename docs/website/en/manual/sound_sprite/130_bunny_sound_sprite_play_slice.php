<div class="prototype">
  Macro
  $Tbool@ $Sbunny_sound_sprite_play_slice@(
  $Tt_bunny_sound_sprite@ *$Ssprite@,
  $Tt_bunny_music_track@ $Strack@,
  $Sname@);
</div>
<hr />

<div class="resume">
  <h3>Description</h3>
  $A Play the subpart named $Sname@ from $Ssprite@. If the sound sprite
  is managed by a t_bunny_sound_manager, then precise a track or if it is
  not the case, use $SBST_LAST_TRACK@.<br />
  <br />
  You cannot play a slice which is already being played.
</div>
<hr />

<div class="parameters">
  <h3>Parameters</h3>
  <ul>
    <li>
      $Tt_bunny_sound_sprite@ *$Ssprite@:<br />
      $A The sound sprite that contains the sound slice you want to play.
    </li>
    <li>
      $Tt_bunny_sound_track@ $Strack@:<br />
      $A The music track that will get occupied by the sent sound sprite
      if the sound sprite is managed by a t_bunny_manager. If it is not
      the case, this parameter will be ignored. Use $SBST_LAST_TRACK@ to
      explicit that the sound sprite is not managed.
    </li>
    <li>
      $Sname@:<br />
      $A The name or id of the slice. It can be a string or a hash generated
      by bunny_sound_sprite_slice_name from the string.
    </li>
  </ul>
</div>
<hr />

<div class="return">
  <h3>Return value</h3>
  <ul>
    <li>
      On $Bsuccess@, the function returns $Ctrue@, which means the slice will
      be played.
    </li>
    <li>
      On $Bfailure@, it returns $Cfalse@ and the slice will not be played.
    </li>
  </ul>
</div>
<hr />

<div class="error_and_log">
  <h3>Error values and logs</h3>
  <p>
    On error, $Vbunny_errno@ is set to:
  </p>
  <br />
  <ul>
    <li>
      $CENOMEM@:<br />
      <p>
        Out of memory.<br />
      </p>
    </li>
    <li>
      $CBE_CANNOT_FIND_ELEMENT@:<br />
      <p>
        The sent $Sname@ is not the name of any slice inside the sound sprite.
      </p>
    </li>
  </ul>
  <br />
  <p>
    Logs written by this function or subfunctions may be tagged with
    $L"ressource"@,
    $L"configuration"@,
    $L"sound"@,
    $L"syntax"@ or
    $L"sound_sprite"@
    labels.
  </p>
</div>
<hr />

<div class="related_functions">
  <h3>Related functions</h3>
  <ul>
    <li>bunny_delete_sound</li>
    <li>bunny_sound_sprite_stop_slice</li>
    <li>bunny_sound_sprite_trap_or_sync</li>
    <li>bunny_sound_sprite_is_talking</li>
  </ul>
</div>
