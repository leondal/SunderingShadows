// Plate Mail Armor for an Imperial Guardsman of Tsarven
// Thorn@ShadowGate
// 11/24/95
// Tsarvani Imperial Guard
// garmor.c

#include <std.h>

inherit "/std/armour.c";

void create() {
    ::create();
    set_name("armor");
    set("id", ({ "armor", "plate mail armor", "plate mail", "plate", "tsarvenigx" }) );
    set("short", "a suit of plate mail armor");
		set_long(
@TSARVEN
	This is a suit of plate mail armor.  The crest of the cresent moon
and three stars on the breastplate identifies this is as armor worn
by a member of the Tsarvani Imperial Guard.
TSARVEN
	);
    set_weight(50);
    set("value", 600);
    set_type("chain");
    set_limbs( ({ "torso" }) );
    set_ac(7);
    set("read", "Ex australis, lux");
}
