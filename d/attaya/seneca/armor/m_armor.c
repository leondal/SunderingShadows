#include <std.h>
inherit "/std/plate";

string OWNER;
void init() {
::init();
if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

 
void create() {
    ::create();
    set_name("armor of the midnight struggle");
    set("id", ({ "armor of the midnight struggle", "armour", "armour of the midnight struggle","plate",
		"armor","midnight struggle",
		"midnight" }) );
    set("short", "Armor of the Midnight Struggle");
    set_long("
    This dark plate mail is painted black with blue stripes that fade inwards from the edges of the breastplate and get brighter until ther reach a white  sphere at the base of the breastplate.  It is relatively light armor.
");
    set_weight(30);
    set("value", 20000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(6);
        set_property("enchantment",1);
        set_wear((:this_object(), "extra_wear":));
   set_remove("%^BOLD%^%^BLUE%^You slip out of the dark armor.");
}
int extra_wear() {
    if((int)TP->query_level() < 10) {
    notify_fail("You are not ready for this armor.");
    return 0;
    }
if((string)TP->query_name() != OWNER) {
   write("%^RED%^The armor shrieks then explodes into a million billion itty bitty pieces as a voice whispers in your head: %^RESET%^You are not worthy");
TO->remove();
return 0;
}
    write("%^BOLD%^%^BLUE%^You slip into the shadowy Armor of the Midnight Struggle and feel more intimidating.");
    return 1;
}
