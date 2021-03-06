<div class="prototype">
  Macro
  $Tvoid@ *$Sbunny_vector_address@($Tt_bunny_vector@ *$Svector@, $Tsize_t@ $Sidx@);
</div>
<hr />

<div class="resume">
  <h3>Description</h3>
  $A Return the address of the element at position idx in vector.
</div>
<hr />

<div class="parameters">
  <h3>Parameters</h3>
  <ul>
    <li>
      $Tt_bunny_vector@ *$Svector@:<br />
      $A The vector to extract informations from.
    </li>
    <li>
      $Tsize_t@ $Sidx@:<br />
      $A The index of the element you want to the address.
      Must not be greater than the vector size minus 1.
    </li>
  </ul>
</div>
<hr />

<div class="return">
  <h3>Return value</h3>
  <ul>
    <li>
      This function returns the address of the element at position idx in vector.
    </li>
  </ul>
</div>

