#include <std.h>
inherit ARMOUR;

string OWNER;
void init() {
::init();
if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

 
void create() {
    ::create();
    set_name("armor of the citadel of whispers");
    set("id", ({ "armor of the citadel of whispers", "armour", "armour of the citadel of whispers","plate",
		"armor","citadel of whispers",
		"citadel" }) );
    set("short", "%^CYAN%^Armor of the Citadel of Whispers%^RESET%^");
    set_long("
   This is one of the original armor designs employed by the elite warriors of the Cartahena Empire.  It has a shiny finish high on the breastplate that fades to deep blue near the bottom.  It has a series of dark blue alloy bands that protect the stomach and waist.  It has a falcon molded into the front of the breastplate.  The design is raised from the surface.
");
    set_weight(50);
    set("value", 50000);
set_size(random(2) + 1);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(9);
        set_property("enchantment",2);
        set_wear((:this_object(), "extra_wear":));
   set_remove("%^BOLD%^%^CYAN%^You remove the powerful armor.");
}
int extra_wear() {
    if((int)TP->query_level() < 20) {
    notify_fail("You are not ready for this armor.");
    return 0;
    }
if((string)TP->query_name() != OWNER) {
   write("%^RED%^The armor shrieks then explodes into a million billion itty bitty pieces as a voice whispers in your head: %^RESET%^You are not worthy");
TO->remove();
return 0;
}
    write("%^BOLD%^%^CYAN%^You slip into the powerful Armor of the Citadel of Whispers and feel very protected.");
    return 1;
}
