
#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long" }));
   set_name("longsword");
   set_short("A long sword");
   set_long(
   "This longsword is a straight bladed, double-edged sword." 
    "  It's thinner than the broad and bastard sword, but a bit longer in length."
  "  It looks very effective as its combination of an edge, point, speed and length make it more versatile than many other weapons."
   );
   set_weight(7);
   set_size(2);
   set("value", 15);
   set_wc(1,8);
   set_large_wc(1,12);
set_type("slashing");
   set_weapon_speed(5);
}
