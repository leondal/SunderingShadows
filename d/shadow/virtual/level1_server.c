#include <std.h>
#include <config.h>
#include <daemons.h>

inherit "/d/shadow/virtual/dinherit";
inherit "/std/virtual/compile";

/* define a few macros... */
#define BASE            "/d/shadow/virtual/level1/"
#define _DAEMON   "/d/shadow/virtual/level1_daemon"
#define SUFFIX          ".level1"

/* prototype some member functions... */
void virtual_setup( string loc );
void init();
string query_short();
string query_long( string str );
string query_smell( string str );
string query_listen( string str );
int is_virtual();

/* define a few data members... */
int x, y;               /* coordinates for this room */


/*****
 * void virtual_setup( string loc );
 *  -- called by the virtual daemon to create a new virtual room.
 *     essentially the same as the create() driver apply for objects.
 *     'loc' has the x and y location of the room to create in the
 *     form of "x,y"
 *****/
void virtual_setup( string loc )
{
  int i;
  string n, s, e, w, ne, nw, se, sw;

  seteuid( getuid() );

  /* set the room properties */
  sscanf( loc, "%d,%d", x, y );
  set_property( "light", 2 );
  /*  set_exits( ({ }), ({ }) ); -- shouldn't be necessary */

  n = sprintf( "%s%d,%d%s", BASE, x, y - 1, SUFFIX );
  s = sprintf( "%s%d,%d%s", BASE, x, y + 1, SUFFIX );
  e = sprintf( "%s%d,%d%s", BASE, x + 1, y, SUFFIX );
  w = sprintf( "%s%d,%d%s", BASE, x - 1, y, SUFFIX );
  ne = sprintf( "%s%d,%d%s", BASE, x + 1, y - 1, SUFFIX );
  nw = sprintf( "%s%d,%d%s", BASE, x - 1, y - 1, SUFFIX );
  se = sprintf( "%s%d,%d%s", BASE, x + 1, y + 1, SUFFIX );
  sw = sprintf( "%s%d,%d%s", BASE, x - 1, y + 1, SUFFIX );

  i = ( int )_DAEMON->get_exit( x, y );


  if ( i & ( 1 << 0 ) )    add_exit( n, "north" );
  if ( i & ( 1 << 1 ) )    add_exit( s, "south" );
  if ( i & ( 1 << 2 ) )    add_exit( e, "east" );
  if ( i & ( 1 << 3 ) )    add_exit( w, "west" );
  if ( i & ( 1 << 4 ) )    add_exit( ne, "northeast" );
  if ( i & ( 1 << 5 ) )    add_exit( nw, "northwest" );
  if ( i & ( 1 << 6 ) )    add_exit( se, "southeast" );
  if ( i & ( 1 << 7 ) )    add_exit( sw, "southwest" );
}


/*****
 * void init();
 *  -- driver apply that is called whenver an object is moved into this room
 *****/
void init()
{
  dinherit::init();
}


/*****
 * string query_short();
 *  -- returns the short description for the room
 *****/
string query_short()
{
  return ( string )_DAEMON->get_short( x, y );
}


/*****
 * string query_long( string str );
 *  -- returns the string for the object that the player wishes to look at.
 *     'str' is what the player decided to look at
 *****/
string query_long( string str )
{
  if ( str )
    return ( string )this_object()->describe( str );

  return sprintf( "%s\n%s\n", ( string )_DAEMON->get_short( x, y ),
		  ( string )_DAEMON->get_long( x, y ))	;
//                  identify( ( int )_DAEMON->get_exit( x, y ) ) );
}


/*****
 * string query_smell( string str );
 *  -- called when the player smells in the current room.  'str' is what
 *     the player is trying to smell, or "default" if they did not
 *     specify anything
 *****/
string query_smell( string str )
{
  if ( !str )
    return 0;

  if ( str != "default" )
    return 0;

      return "The smell of old old decay permeates the air.";
 }


/*****
 * string query_listen( string str );
 *  -- called when the player listens in the current room.  'str' is what
 *     they are listening to, or "default" if they did not specify anything
 *****/
string query_listen( string str )
{
  if ( !str )
    return 0;

  if ( str != "default" )
    return 0;

      return "A scratch .. a crunch .. a creak ... a moan?";
 }


/*****
 * int is_virtual();
 *  -- returns 1 stating that this is a virtual room
 *****/
int is_virtual()
{
  return 1;
}

