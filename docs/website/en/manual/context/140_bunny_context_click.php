<div class="prototype">
  $Tt_bunny_response@ $Sbunny_context_click@(
  $Tt_bunny_event_state@ $Sstate@,
  $Tt_bunny_mouse_button@ $Ssym@,
  $Tvoid@ *$Sdata@
  );
</div>
<hr />

<div class="resume">
  <h3>Description</h3>
  $A The real type of the third parameter is t_bunny_context_runtime_info.
  This function does nothing except calling $Ssubcontext.click@ if not $CNULL@,
  and returning its value.<br />
  This is useful to create a bridge from the current context to the $Ssubcontext@.
</div>

