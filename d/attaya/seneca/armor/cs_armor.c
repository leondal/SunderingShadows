#include <std.h>
inherit ARMOUR;

string OWNER;
void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}


void create() {
    ::create();
    set_name("armor of the citadel of storms");
    set("id", ({ "armor of the citadel of storms", "armour", "armour of the citadel of storms","plate",
	"armor","citadel of storms",
	"citadel" }) );
    set("short", "%^BLUE%^Armor of the Citadel of Storms%^RESET%^");
    set_long(
   "This is one of the original armor designs employed by the elite warriors of the Cartahena Empire.  It has a shiny finish high on the breastplate that fades to deep violet near the bottom.  It has a series of black alloy bands that protect the stomach and waist.  It has a fanged skull molded into the front of the breastplate.  The design is raised from the surface."
    );
    set_weight(50);
    set("value", 75000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(9);
    set_property("enchantment",3);
    set_wear((:this_object(), "extra_wear":));
    set_remove("%^BOLD%^%^BLUE%^You remove the powerful armor.");
}
int extra_wear() {
    if((int)TP->query_level() < 30) {
	notify_fail("You are not ready for this armor.");
	return 0;
    }
    if( ((string)TP->query_name() != OWNER) && ((string)TP->query_name() != "Shadowy Implementor")) {
   write("%^RED%^The armor shrieks then explodes into a million billion itty bitty pieces as a voice whispers in your head: %^RESET%^You are not worthy");
	TO->remove();
	return 0;
    }
    write("%^BOLD%^%^BLUE%^You slip into the powerful Armor of the Citadel of Storms and feel very protected.");
    return 1;
}
