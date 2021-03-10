#include <std.h>
inherit ARMOUR;

string OWNER;
void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create() {
    ::create();
    set_name("armor of the crimson wave");
    set("id", ({ "armor of the crimson wave", "armour", "armour of the crimson wave","plate",
	"armor","crimson wave",
	"midnight" }) );
    set("short", "%^RED%^Armor of the Crimson Wave%^RESET%^");
    set_long("
   %^RED%^This medium armor is painted a dark red and is highly reflective.  It looks like it was forged of blood itself as it has the same luster and color.  It is built of several interlocking body plates.
");
    set_weight(40);
    set("value", 32000);
    set_type("armour");
set_size(random(2) + 1);
    set_limbs( ({ "torso" }) );
    set_ac(9);
        set_property("enchantment",2);
        set_wear((:this_object(), "extra_wear":));
   set_remove("%^BOLD%^%^RED%^You slip out of the crimson armor.");
}
int extra_wear() {
if((string)TP->query_name() != OWNER) {
write("%^RED%^The armor shrieks then explodes into a million billion itty bitty pieces as a voice whispers in your head: %^RESET%^You are not worthy");
TO->remove();
return 0;
}
if((int)TP->query_level() < 27) {
    notify_fail("You are not ready for this armor.");
    return 0;
    }
    write("%^BOLD%^%^RED%^You connect the interlocking plates of the Armor of the Crimson Wave.");
    return 1;
}
