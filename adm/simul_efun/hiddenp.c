/*
// File:	hiddenp.c (simul_efun)
// Syntax:      int hiddenp( object ob )
// Return:	0 or 1
// Effect:	0 if ob is not a hidden object
//              1 if ob is     a hidden object
// Date V1.0:   1992 December 18
// Mudlib:      TMI-II
// Author:      Pallando (aka Douglas Reay)
// Comments:	Called a Daemon with a non-root euid
// Date V1.1:   1993 January 9
// Comments:	It now changes the simul_efun object's euid
// Date V1.2:   1993 May 28
// Comments:    Installed on Nightmare.
*/

/**
 * @file
 */

/**
 * Checks whether an object is hidden. That is not the same as invisibility.
 *
 * @param ob Object
 * @return 0 if is not hidden, 1 if is hidden
 */
int hiddenp( object ob )
{
  string filename;
  int ret;

  if( !objectp( ob ) ) return 0;
  filename = file_name( ob );
  seteuid( 0 );
  ret = !find_object( filename );
  seteuid( getuid( this_object() ) );
  return ret;
}
