// Helm for an Imperial Soldier of Tsarven
// Thorn@ShadowGate
// 11/24/95
// Tsarvani Imperial Army
// ihelm.c

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "a helm");
		set_long(
@TSARVEN
This is a light, but sturdy helm.  The crest of the cresent moon
on the helm idenifies this is as a helm worn by a member of the Tsarvani 
Imperial Army.
TSARVEN
	);
    set_weight(10);
    set("value", 50);
    set_type("armor");
    set_limbs( ({ "head" }) );
    set_ac(1);
}
