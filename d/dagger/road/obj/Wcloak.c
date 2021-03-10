#include <std.h>
inherit "/std/armour";

void create() {
   ::create();
set_name("long white leather cloak");
set("id", ({ "cloak","leather cloak","white leather cloak"}) );
set("short", "A long white leather cloak");
set("long", "%^BOLD%^This is a long white leather cloak.
It's made of soft leather of some animal and treated to resist
the elements. It's standard issue equipment for the Army of the
Dagger Reaches.");
set_weight(2);
set("value", 20);
set_type("clothing");
set_limbs( ({ "neck" }) );
set_ac(0);
}
