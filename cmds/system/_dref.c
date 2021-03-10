// File:        _dref.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     destructs a reference'd object
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: dref <object>\n"

int cmd_dref( string a )
{
  mixed ob;

  if( !a ) { notify_fail( SYNTAX ); return 0; }
  seteuid( geteuid( previous_object() ) );

  ob = ref_ob( a );
  if( !objectp( ob ) )
  {
    notify_fail( wrap( "Could not identify " + identify( ob ) +
      " as an object." ) );
    return 0;
  }
  a = identify( ob );
  catch( ob-> remove() );
  if( !ob )
  {
    write( a + " has been removed.\n" );
    return 1;
  }
  catch( destruct( ob ) );
  if( !ob )
  {
    write( a + " has been destructed.\n" );
    return 1; 
  }
  write( "You could not destruct " + a + "\n" );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: Tries to remove then destruct object <object>\n"+
    "See also: refs, dest\n"+
  "" );
  return 1;
}
