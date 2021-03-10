#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
set_name("curved deflection shield");
set("id", ({ "curved deflection shield", "curved shield","shield","deflection shield"}) );
set("short", "Curved deflection shield");
    set_long("
    This is a wooden shield with a slippery waxed surface.  It has a drastically curved surface that is almost spherical.
    It has been designed to deflect attacks.
   ");
set_weight(10);
set("value", 1000);
set_type("shield");
set_limbs( ({ "left hand" }) );
set_ac(1);
set_property("enchantment", 2);
}
