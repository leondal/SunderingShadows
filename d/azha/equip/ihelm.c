// Helm for an Imperial Soldier of Tsarven
// Thorn@ShadowGate
// 11/24/95
// Tsarvani Imperial Army
// ihelm.c

#include <std.h>

inherit "/d/common/obj/armour/helm.c";

void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "helmet", "great helm" }) );
    set("short", "a helm");
		set_long(
@TSARVEN
This is a sturdy helm.  The crest of the cresent moon
on the helm idenifies this is as a helm worn by a member of the Tsarvani 
Imperial Army.
TSARVEN
	);
}
