// Helm for an Imperial Guardsman of Tsarven
// Thorn@ShadowGate
// 11/24/95
// Tsarvani Imperial Guard
// ghelm.c

#include <std.h>

inherit "/std/armour.c";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "a helm");
		set_long(
@TSARVEN
This is a light, but sturdy helm.  The crest of the cresent moon
and three stars on the helm idenifies this is as a helm worn by
a member of the Tsarvani Imperial Guard.
TSARVEN
	);
    set_weight(10);
    set("value", 50);
    set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set("read", "Ex australis, lux");
}

int is_tsarvani_guard() { return 1; }
