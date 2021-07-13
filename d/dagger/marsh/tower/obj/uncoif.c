// fixed wear/unwear to use ETO - last change was 7/98  *Styx* 8/2003
//Changed class check to paladin, since there are no more antipaladins
//~Circe~ 1/4/13

#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("helm");
    set_id( ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set_short("Chain coif of Death");
    set_long("This is a decorative light chain coif worn "
	"by members of the Black Order of Paladins.");
    set_weight(10);
    set_value(25);
    set_type("armour");
    set_limbs( ({ "head" }) );
    set_ac(1);
    set_property("enchantment",4);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}

int wearit() {
    if(!ETO->is_class("paladin")) {
	write("You may not wear this armour!");
	return 0;
    }
    write("%^BLUE%^You feel more protected by the chain coif!%^RESET%^");
    tell_room(environment(ETO),"%^BLUE%^"+TPQCN+" glows with an evil light!"
	    "%^RESET%^",ETO);
    return 1;
}

int removeit() {
    tell_object(ETO,"You remove the coif and feel less protected." );
    return 1;
}
