//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("silk cloak");
	set_id(({ "cloak", "silk cloak" }));
	set_short("%^BOLD%^%^RED%^Red Silk Cloak%^RESET%^");
	set_obvious_short("A red silk cloak");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This shiny red cloak is made of the finest quality silk.  It will provide you with some protection during combats.  The cloak features a %^BLUE%^sapphire blue%^RED%^ silk boarder.

AVATAR
	);
	set_weight(5);
	set_value(1200);
	set_lore(
@AVATAR
This red silk cloak is often used by a band of apprenticed dedicated to a mysterious mage who is rumored to live on Deku.  The apprentices train hard under the guide of their master in hopes that one day the might become a might mage like he is.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3+random(2));
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set_item_bonus("magic resistance",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" ties on a red silk cloak.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You tie the red silk cloak on and feel protected.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" unties the red silk cloak",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You untie the red silk cloak");
	return 1;
}
