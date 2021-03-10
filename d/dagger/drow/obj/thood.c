//Updated obvious short to have color, colors submitted by Kain - Octothorpe 6/9/09
// changed from 1AC/+1 to 0AC/+2, to put it in line with leather headpiece standards. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("hood");
	set_id(({ "hood" }));
	set_short("%^BOLD%^%^BLACK%^A thief's hood%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^A hood made of %^BLUE%^s%^RESET%^%^BLUE%^h%^BOLD%^ado%^RESET%^%^BLUE%^w%^BOLD%^s%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This hood covers the wearers head comfortably, masking it from view in an array of shadows. It is made of a thin black fabric that is extremely soft and smooth, but somehow seems as if it will still provide some form of protection.

AVATAR
	);
	set_weight(2);
	set_value(1000);
      set_type("leather");
	set_limbs(({ "head" }));
	set_size(2);
    set_property("enchantment",6);
    set_item_bonus("stealth",4);
    set_item_bonus("thievery",4);
    set_item_bonus("perception",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
   if((int)ETO->query_highest_level() < 20) {
   tell_object(ETO,"%^BOLD%^%^BLACK%^The hood rejects you.");
   return 0;
   }
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" slips on the black hood, sliding into the shadows of the hood.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip on the black hood.");
	return 1;
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip off the black hood.");
	return 1;
}
