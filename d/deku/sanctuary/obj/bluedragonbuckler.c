//Updated to bring in line with area difficulty - Octothorpe 4/15/10
//Fixed description where it cut off ~Circe~ 5/4/11. Also, there was a 
//bug report that this was "light" armor instead of a "shield" but that
//seems to be intended for thieves, so leaving as is for now.

#include <std.h>
inherit "/d/common/obj/armour/buckler.c";

void create(){
	::create();
	set_name("buckler");
	set_id(({ "buckler", "cobalt buckler", "shield" }));
	set_short("%^BOLD%^%^BLUE%^Cobalt Buckler%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLUE%^A blue buckler%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^This small shield made from cobalt blue leather straps onto your forearm.  Many find the buckler better than a shield, as it is not as cumbersome and does not hamper your mobility.  The leather used for this buckler is a brilliant rich shade of cobalt blue stretched over a metal backing.  Soft but strong straps are made of the same leather material.  Branded into the leather along the outer edge is a pattern of %^CYAN%^s%^BLUE%^w%^WHITE%^i%^BLUE%^r%^CYAN%^l%^WHITE%^s%^BLUE%^.%^RESET%^
AVATAR
	);
	set_weight(5);
	set_value(300);
	set_lore(
@AVATAR
The Cobalt Buckler is rumored to be made from the hide of a Blue Dragon.  Though other swear it is made from the flesh of a neried or selkie dyed blue.  Still others claim it is just dyed lizard skin and there is nothing special about it.  Which is true is hard to say.
AVATAR
	);
	set_property("lore",8);
  set_property("enchantment",3+random(2));
	set_wear((:TO,"wear_func":));
}
int wear_func(){
	if((int)ETO->query_level() < 15) {
   	notify_fail("The buckler refuses to strap to your arm!");
    	return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" "+
		"straps on the "+query_short()+".",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You strap on the "+query_short()+".");
	return 1;
}
