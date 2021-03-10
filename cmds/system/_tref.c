// File:        _tref.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     does tell_object to a reference'd object
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: [<object>;]<message>\n"

int cmd_tref( string a )
{
  mixed ob, tmp;
  string mess;

  if( !a ) { notify_fail( SYNTAX ); return 0; } 
  seteuid( geteuid( previous_object() ) );

  if( sscanf( a, "%s;%s", ob, mess ) < 2 )
    { ob = "#default"; mess = a; }

  a = ob;
  ob = ref_ob( ob );
  if( !objectp( ob ) )
  {
    if( a == "#default" ) notify_fail( SYNTAX ); else
    notify_fail( wrap( "Could not identify " + a + " as an object." ) );
    return 0; 
  }
  tmp = resolv_ref( mess );
  if( stringp( tmp ) ) mess = tmp;
  tell_object( ob, mess );
  write( wrap( "You tell " + identify( ob ) + " " + identify( mess ) ) );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: tell <message> to <object>\n"+
    "See also: refs\n"+
  "" );
}
