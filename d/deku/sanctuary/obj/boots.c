//Updated to bring in line with area difficulty - Octothorpe 4/15/10
#include <std.h>
#include "../dragon.h";
inherit ARMOUR;
create() {
    ::create();
    set_name("boots");
    set_id(({"boots","boot","leather boots","hardened leather boots"}));
    set_short("%^BOLD%^%^BLACK%^Hardened leather boots%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^A pair of black leather hard boots%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These small hard boots have been crafted from"+
		" boiled leather.  The rigid leather seems as if it would provide"+
		" protection to the feet of the wearer.  Stitched into the hard"+
		" leather is a geometrical pattern of squares, diamonds, and "+
		"triangles.  The thick hard soles of the boots are caked with"+
		" dried mud.");
    set_lore("Gnomish boots are usually made to be rigid and inflexible, little like their creators.  "+
"Their skill in the creation of rugged footwear stems from their underground habitations.  Because "+
"of the large amounts of rock, mud, and other debris firm and solid footware is needed.  They serve to "+
"protect the feet well from harm.");
    	set_property("lore",7);
	set_weight(2);
    	set_value(150);
    	set_size(1);
    set_property("enchantment",3);
    set_type("clothing");
    set_limbs(({"left foot","right foot"}));
    set_ac(0);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    tell_object(TP,"%^BOLD%^%^BLACK%^You slide your feet into the comfortable boots.");
    return 1;
}
int removeit() {
    tell_object(ETO,"%^BOLD%^%^BLACK%^You slide your feet out of the comfortable boots.");
    return 1;
}

void init() {
   ::init();
   if(query_property("enchantment") > 0 && query_property("enchantment") != 3) {
     while(query_property("enchantment") != 3) {
       remove_property("enchantment");
       set_property("enchantment",3);
     }
   }
}