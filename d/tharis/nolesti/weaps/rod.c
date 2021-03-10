// Coded by Arson

#include <std.h>
inherit "/std/weapon";

void create()
{
    ::create();
    set_id( ({ "rod", "weapon", "golden rod", "a golden rod" }) );
    set_name( "golden rod" );
    set_short( "a Golden Rod" );
    set_long(
     "This is a brightly shining golden rod.  It looks somewhat "
      "like a sceptre, but it belonged to the Advisor Justarius.  "
      "There is a long strand of white horse hair at the tip."
    );
    set_weight(5);
    set_size(2);
    set_wc(1,6);
    set_large_wc(1,7);
    set_value(895);
    set_type("bludgeoning");
}
