// changed to +1 with new enchantment settings, nienne 05/07
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
        set_id(({ "cloak", "cloak of shadows", "black cloak" }));
	set_short("%^BOLD%^%^BLACK%^Cloak of Shadows%^RESET%^");
	set_obvious_short("a black cloak");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This cloak is crafted from an odd black material, that is almost like a thin silk.  The cloak is sheer enough that one can just almost see through it, though everything viewed will be seen in a dark haze.

AVATAR
	);
	set_weight(5);
	set_value(75);
	set_lore(
@AVATAR
The Cloak of Shadows is often seen with members of dark faith.  It is rumored that the cloak has the ability to diminish the light of a room just by it's presence.  Some even suspect the cloak was woven from the shadows itself.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "neck" }));
        if(random(3)) set_size(2);
        else set_size(1);
        set_property("enchantment",1);
      set_item_bonus("sight bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The lighting about you fades in intensity.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The lighting about you fades in intensity.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Things suddenly seem brighter about you!",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^Things suddenly seem brighter about you!");
	return 1;
}
