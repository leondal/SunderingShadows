// fixed wear/unwear to use ETO-last change was 7/98  *Styx* 8/2003

#include <std.h>
inherit "/std/armour";
 
void create() {
    ::create();
    set_name("helm");
    set_id( ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    set_short("Chain coif of the Order");
    set_long("This is a decorative light chain coif worn "
	"by members of The Paladin Order.");
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
	write("You may not wear this armour!\n");
	return 0;
  } else {
        write("%^YELLOW%^You feel more protected by the chain "
	    "coif!%^RESET%^");
        tell_room(environment(ETO),"%^YELLOW%^"+TPQCN+" glows with an inner light!"
	    "%^RESET%^",ETO);
        return 1;
  }
}
int removeit() {
    tell_object(TP,
        "You remove the coif and feel less protected."
    );
    return 1;
}
