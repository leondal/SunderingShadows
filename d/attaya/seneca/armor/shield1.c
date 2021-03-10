#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
set_name("aster shield");
set("id", ({ "aster shield", "star shield","shield","steel aster shield"}) );
set("short", "Aster shield");
    set_long("
    This is a star-shaped shield with grooves designed to catch your opponent's weapon in a side-strike.
    It is made of steel and can take quite a beating.
   ");
set_weight(20);
set("value", 4000);
set_type("shield");
set_limbs( ({ "right hand" }) );
set_ac(1);
set_property("enchantment", 1);
}
