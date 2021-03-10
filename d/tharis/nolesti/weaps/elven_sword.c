// Coded by Arson@ShadowGate 1/2/96

#include <std.h>
inherit "/std/weapon";

create()
{
    ::create();
    set_id( ({ "sword", "elven sword", "an elven sword" }) );
    set_name( "elven sword" );
    set_short( "an elven sword" );
    set_long(
      "This is a small and light sword of Elven make.  It looks like it "
      "makes a good fighting weapon because of it's lightness, you can "
      "swing with ease.  The blade is curved and sharpened very well.  "
      "The hilt is decorated by green leaves etched onto it."
    );
    set_weight( 2 );
    set_size( 1 );
    set_wc( 1, 7 );
    set_large_wc( 1, 9 );
    set( "value", 15 );
    set_type( "slashing" );
}
