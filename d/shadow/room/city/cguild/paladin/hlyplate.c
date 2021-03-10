#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("fullplate");
    set("id", ({ "armour", "full plate armour","plate",
		"full plate","full plate of the order",
		"plate of the order","full plate armour of "
		"the order" }) );
    set("short", "Full plate armor of the Order");
    set("long",
        "This is the impressive, high gothic style armor of the late "
"middle ages and renaissance. It is perfectly forged and fitted. All the  "
"plates are interlocking and carefully angled to deflect blows. The metal "
"plates are backed by padding and chainmail. The weight is well "
"distributed. The armor is crafted exclusively by holy dwarven "
"smiths and blessed by clerics of renown power lending it a "
"quality of cooled temperature and light weight. It is worn by "
"the loyal order of Paladins found within Shadowgate."
       );
    set_weight(50);
    set("value", 6000);
    set_type("armour");
    set_property("no animate",1);
    set_limbs( ({ "torso" }) );
    set_ac(9);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    if(!TP->is_class("paladin")) {
	notify_fail("You may not wear this armour!\n");
	return 0;
    } else {
        write(
            "You feel the %^BOLD%^%^YELLOW%^holy power%^RESET%^"
	    " of your god as you don the armour!"
        );
        say(
	    "%^YELLOW%^"+TPQCN+" glows with a holy power!"
	    "%^RESET%^"
	,TP);
        return 1;
    }
}
int removeit() {
    tell_object(TP,
        "You feel less protected from the darkness of "
        "Shadowgate."
    );
    return 1;
}
