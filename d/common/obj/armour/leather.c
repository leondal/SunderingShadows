#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(8);
    set_armor_prof("light");
    set_name("leather");
    set("id", ({ "leather","leather armor", "armor", "armour" }) );
    set("short", "A suit of leather armor");
    set("long", 
	"This armor is made of leather, hardened in boiling oil and then "
	"shaped into breastplate and shoulder protectors. The rest of the "
    "suit is made of softer, more flexible materials."
       );
    set_weight(14);
    set("value", 5);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}

int is_metal() { return 0; }
