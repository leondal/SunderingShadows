// File:        _unref.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     unsets a reference
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: unref <ref_name>\n"

int cmd_unref( string a )
{
  mapping refs;

  if( !a ) { notify_fail( SYNTAX ); return 0; }
  if( undefinedp( get_ref( a ) ) )
  {
    notify_fail( "\"" + a + "\" is not a reference.\n" );
    return 0;
  }
  set_ref( a, ([])["undefined"] );
  write( "Reference \"" + a + "\" deleted.\n" );
  return 1;
}

int help() 
{
  write( SYNTAX +
    "Effect: unsets reference <ref_name>\n"+
    "See also: refs\n"+
  "" );
  return 1;
}
