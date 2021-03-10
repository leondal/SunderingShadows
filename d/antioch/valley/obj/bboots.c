#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
      set_obvious_short("A pair of black leather boots");
	set_name("Black Boots");
	set_id(({"boots","black boots","shoes","shadow boots"}));
	set_short("%^BLACK%^%^BOLD%^Black Boots%^RESET%^");
	set_long(
         "This is a nice pair of black leather boots. The leather has been hardened "+
         "so as to withstand harsh conditions. The boots reach up to just below the "+
         "knee, protecting the wearer from low-lying threats. The boots fasten on the "+
         "side with a series of small buckles, allowing for high adjustability.");
	set_size(2);
    set_property("enchantment",1+random(2));
	set_weight(5);
	set_value(300);
	set_cointype("silver");
	set_type("clothing");
	set_limbs(({"right foot","left foot"}));
	set_wear((:TO, "wearme":));
	set_remove((:TO, "removeme":));
}

int wearme()
{
    if((int)ETO->query_highest_level() < 10){
	    tell_object(ETO,"%^BOLD%^%^BLACK%^You are unable to properly fasten the buckles.");
		return 0;
	}
        tell_object(ETO,"%^BOLD%^%^BLACK%^You stomp your feet into the boots and "+
         "buckle up the sides.");
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^%^BLACK%^You take off the boots and feel much "+
         "less protected.");
	return 1;
}
