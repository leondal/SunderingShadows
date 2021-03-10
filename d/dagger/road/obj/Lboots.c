#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
set_name("tough leather boots");
set("id", ({ "tough leather boots","boots","leather boots"}) );
set("short", "A pair of tough leather boots");
set("long", "This is a pair of tough leather boots.
they're made of the tough leather of some animal and treated to resist
the elements. They're standard issue equipment for the Army of the
Dagger Reaches.");
set_weight(5);
set("value", 25);
set_type("boots");
set_limbs( ({ "right foot","left foot" }) );
set_ac(0);
}
