// fixed wear/unwear to use ETO - last change was 12/99  *Styx* 8/2003
//Changed class check to paladin, since there are no more antipaladins
//~Circe~ 1/4/13

#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("fullplate");
    set_id( ({ "armour", "full plate armour","plate",
		"full plate","full plate of death",
		"plate of death","full plate armour of "
		"death" }) );
    set_short("Full plate armor of Death");
    set_long("This is the impressive, high gothic style armor of the late "
        "middle ages and renaissance. It is perfectly forged and fitted. All the  "
	"plates are interlocking and carefully angled to deflect blows. The metal "
	"plates are backed by padding and chainmail. The weight is well "
	"distributed. The armor is crafted exclusively by unholy drow elves "
	"smiths and smiten with evil power by vile clerics of renown power lending it a "
	"quality of cooled temperature and light weight. It is favored by "
	"the order of dark Paladins."
    );
    set_weight(50);
    set_value(6000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(9);
    set_property("enchantment",5);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
     if(!ETO->is_class("paladin")) {
        tell_object(ETO,"You may not wear this armour!");
	return 0;
     }
     if(ETO->query_lowest_level() < 30) {   // lowering to 30 also *Styx*
        tell_object(ETO,"You are not yet powerful enough to wear this armour!");
	return 0;
     }
     write("You feel the %^BOLD%^%^BLUE%^unholy power%^RESET%^"
	    " of the Abyss as you don the armour!");
     tell_room(environment(ETO), "%^BLUE%^"+ETOQCN+" glows with an unholy power!"
	    "%^RESET%^",ETO);
     return 1;
}

int removeit() {
    tell_object(ETO,  "You feel less protected from guardians of the light.");
    return 1;
}
