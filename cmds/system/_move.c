// File:        _move.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     allow wizards to move any object anywhere
// Credits:     see _refs.c

#include <move.h>
#include <daemons.h>
#include <std.h>
#define SYNTAX "Syntax: move <object1> to <object2>\n"

inherit DAEMON;
inherit REFS_D;


int cmd_move( string a )
{
  mixed o1, o2, tmp;
  string str;
  int ret;

    if(member_group(geteuid(previous_object()), "ambassador")) return 0;
  if( !a || ( sscanf( a, "%s to %s", o1, o2 ) < 2 ) )
    { notify_fail( SYNTAX ); return 0; }

  seteuid( geteuid( previous_object() ) );

  o1 = ref_ob( o1 );
  if( !objectp( o1 ) )
  {
    notify_fail( wrap( "Could not identify " + identify( o1 ) +
      " as an object." ) );
    return 0;
  }
  o2 = ref_ob( o2 );
  if( !objectp( o2 ) )
  {
    notify_fail( wrap( "Could not identify " + identify( o2 ) +
     " as an object." ) );
    return 0;
  }
  set_ref( 0, o2 );
  write( wrap( "Moving " + identify( o1 ) + " to " + identify( o2 ) + "..." ) );
  ret = o1-> move( o2 );
  switch( ret )
  {
    case MOVE_OK:		str = "Move OK.\n"; break;
    case MOVE_NOT_ALLOWED:	str = "Move not allowed.\n"; break;
    case MOVE_NO_ROOM:		str = "No room in object2 for object1\n"; break;
    case MOVE_DESTRUCTED:	str = "Move destructed\n"; break;
    case MOVE_NO_DEST:		str = "object2 is not a destination\n"; break;
#ifdef MOVE_TOO_HEAVY
    case MOVE_TOO_HEAVY:	str = "object1 too heavy for object2\n"; break;
#endif /* MOVE_TOO_HEAVY */
#ifdef MOVE_DOOR_CLOSED
    case MOVE_DOOR_CLOSED:	str = "The door is closed.\n"; break;
#endif /* MOVE_DOOR_CLOSED */
    default: str = "Error: move return code " + ret + "\n"; break;
  }
  if( ret == MOVE_OK ) { write( str ); return 1; }
  notify_fail( str ); 
  return 0;
}

int help()
{
  write( SYNTAX +
    "Effect: Moves object1 to inside object2\n"+
    "See man: get_object get_objects\n"+
    "See also: refs\n"+
  "" );
  return 1;
}
