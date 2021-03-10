// File:       /std/user/refs.c
// Mudlib:     Nightmare
// Purpose:    To store refs in (See _refs)
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:  93-06-05

static mapping refs;

void set_refs( mapping a ) { refs = ( mapp( a ) ? a : ([]) ); }

mapping get_refs() { return ( refs ? copy(refs) : ([]) ); }

void set_ref( string ref, mixed value )
{
  if( !refs ) refs = ([]);
  if( !ref ) ref = "default";
  if( undefinedp( value ) )
    map_delete( refs, ref );
  else
    refs[ref] = value;
}

mixed get_ref( string ref )
{
  if( !refs ) refs = ([]);
  if( !ref ) ref = "default";
  return refs[ref];
}
