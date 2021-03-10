// Coded by Arson

#include <std.h>
inherit "/std/weapon";

create()
{
    ::create();
    set_id( ({ "sword", "weapon", "fine elven sword", "elven sword" }) );
    set_name( "fine elven sword" );
    set_short( "a fine elven sword" );
    set_long(
      "This is a fine example of Elven swords.  It's blade is long and "
      "curved.  It is sharpened to a razor-sharp edge and feels "
      "very balanced in your hands.  The hilt is decorated by "
      "carved leaves."
    );
    set_weight( 2 );
    set_size( 2 );
    set_wc( 1, 8 );
    set_large_wc( 1, 9 );
    set( "value", 200 );
    set_type( "slashing" );
}
