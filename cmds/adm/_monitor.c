// File:       /bin/adm/_monitor.c
// Mudlib:     Nightmare
// Purpose:    So you don't miss when someone you want to talk to stops idling.
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// 93-06-25    Based on look 'n' feel of command written by Watcher@TMI-2

#define CTRL_G sprintf( "%c", 7 )
#define SYNTAX "Syntax: monitor <name>\n"

#include <std.h>

inherit DAEMON;

int cmd_monitor( string name )
{
  object victim;

  notify_fail( SYNTAX );
  if( !name || !( victim = find_player( name ) ) ) return 0;
  if( archp( victim ) && !archp( this_player() ) )
  {
    notify_fail( "You may not monitor arches.\n" );
    return 0;
  }
  call_out( "do_monitor", 10, ({ name, previous_object() }) );
  write( "Ok, you will be told when " + name + " stops idling.\n" );
  return 1;
}

void do_monitor( mixed arg )
{
  object obj;

  if( !arg[1] ) return;
  if( !( obj = find_player( arg[0] ) ) )
  {
    tell_object( arg[1], arg[0] + " is no longer logged in.\n" );
    return;
  }
  if( query_idle( obj ) < 15 )
  {
    tell_object( arg[1], arg[0] + " is no longer idle.\n" );
    tell_object( arg[1], CTRL_G );
    return;
  }
  call_out( "do_monitor", 10, arg );
}

int help()
{
  write( SYNTAX + @EndText
Effect: Tells you when <name> is no longer idle.
EndText
  );
  return 1;
}

// Prevent this object being destructed.
void clean_up() {}
