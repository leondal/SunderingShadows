#include <std.h>
inherit ARMOUR;

void init() {
    ::init();
}

void create() {
    ::create();
    set_name("white and silver tabard");
    set("id", ({ "tabard", "alliance tabard", "white tabard" }) );
    set("short", "%^BOLD%^WHITE%^White tabard fringed in silver%^RESET%^");
    set_long(
@ALLIANCE
This is instantly recognizable as the bright white tabard of the 
Defenders of the Light, the elite garrison company of the Alliance of 
Light.  The fringes of the tabard are done in a silver thread as well as 
the Alliance insignia in the center.  
ALLIANCE
	);
	set_weight(2);
	set("value", 0);
	set_type("clothing");
	set_size(random(2) + 1);
	set_limbs( ({ "torso" }) );
	set_ac(0);
}
