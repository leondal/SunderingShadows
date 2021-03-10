#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("leather");
set("id", ({ "leather","leather armor", "armor", "armour" }) );
    set("short", "A suit of leather armor");
    set("long", 
	"This armor is made of leather, hardened in boiling oil and then "
	"shaped into breastplate and shoulder protectors. The rest of the "
	"suit is made of softer, more flexable materials."
       );
    set_weight(15);
    set("value", 5);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}
