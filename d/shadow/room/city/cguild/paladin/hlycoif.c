#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("helm");
    set("id", ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set("short", "Chain coif of the Order");
    set("long", "This is a decorative light chain coif worn "
	"by members of The Paladin Order.");
    set_weight(10);
    set("value", 25);
    set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    if(!TP->is_class("paladin")) {
	notify_fail("You may not wear this armour!\n");
	return 0;
    } else {
        write(
            "%^YELLOW%^You feel more protected by the chain "
	    "coif!%^RESET%^"
        );
        say(
	    "%^YELLOW%^"+TPQCN+" glows with an inner light!"
	    "%^RESET%^"
	,TP);
        return 1;
    }
}
int removeit() {
    tell_object(TP,
        "You remove the coif and feel less protected."
    );
    return 1;
}
