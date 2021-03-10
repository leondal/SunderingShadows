// File:        _cref.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     clones a reference'd object
// Credits:     see _refs.c

#include <move.h>
#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: cref [<object>]\n"

int cmd_cref( string a )
{
  mixed ob;
  object new_ob;
  string name, num;

  seteuid( geteuid( previous_object() ) );

  if( !a ) a = "#default";
  ob = ref_ob( a );
  if( !objectp( ob ) )
  {
    notify_fail( wrap( "Could not identify " + identify( ob ) +
      " as an object." ) );
    return 0;
  }
  name = file_name( ob );
  if( sscanf( name, "%s#%s", ob, num ) < 2 )
    ob = name;
  if( catch( new_ob = new( ob ) ) )
    { notify_fail( "Could not clone " + ob + "\n" ); return 0; }
  write( "CLONE: You have created " + identify( new_ob ) + "\n" );
  if( new_ob-> move( this_player() ) != MOVE_OK )
    new_ob-> move( environment( this_player() ) );
  set_ref( 0, new_ob );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: clones you a copy of <object>\n"+
    "See also: refs, clone\n"+
  "" );
  return 1;
}
