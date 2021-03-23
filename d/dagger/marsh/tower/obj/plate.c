// fixed wear/unwear to use ETO - last change was 7/03  *Styx* 8/2003

#include <std.h>
inherit "/d/common/obj/armour/fullplate";
 
void create() {
    ::create();
    set_name("fullplate");
    set_id( ({ "armour", "full plate armour","plate",
		"full plate","full plate of the order",
		"plate of the order","full plate armour of "
		"the order" }) );
    set_short("Full plate armor of the Order");
    set_long("This is the impressive, high gothic style armor of the late "
        "middle ages and renaissance. It is perfectly forged and fitted. All the  "
	"plates are interlocking and carefully angled to deflect blows. The metal "
	"plates are backed by padding and chainmail. The weight is well "
	"distributed. The armor is crafted exclusively by holy dwarven "
	"smiths and blessed by clerics of renown power lending it a "
	"quality of cooled temperature and light weight. It is favored by "
	"the loyal order of Paladins."
    );
    set_value(6000);
    set_property("enchantment",5);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}

int wearit() {
    if(!ETO->is_class("paladin")) {
	write("You may not wear this armour!\n");
	return 0;
    }
    if(ETO->query_lowest_level() < 30) { // lowering to 30 also *Styx*
	write("You are too inexperienced to wear this armor!\n");
	return 0;
    }
    write("You feel the %^BOLD%^%^YELLOW%^holy power%^RESET%^"
	    " of your god as you don the armour!");
    tell_room(environment(ETO), "%^YELLOW%^"+TPQCN+" glows with a holy power!"
	    "%^RESET%^"	,ETO);
    return 1;
}

int removeit() {
    tell_object(ETO,"You feel less protected from the darkness.");
    return 1;
}
