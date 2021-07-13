#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("black boots");
	set_id(({ "boots" }));
	set_short("%^BOLD%^%^BLACK%^Ze%^BOLD%^%^YELLOW%^alo%^BOLD%^%^BLACK%^t's Motion%^RESET%^");
        set_obvious_short("%^BOLD%^%^BLACK%^Black boots%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^These heavy black boots have %^BOLD%^%^WHITE%^silver %^BOLD%^%^BLACK%^buckles. The buckles attach to a fixed metal plate on the right side, seemingly to offer good support to the ankle. Along the back of the boots, a %^BOLD%^%^YELLOW%^strip %^BOLD%^%^BLACK%^is placed with %^BOLD%^%^GREEN%^etching %^BOLD%^%^BLACK%^upon it.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
%^BOLD%^%^YELLOW%^Before it, one must prevail.%^RESET%^

AVATAR
	);
     set("langage","str");     set_weight(1);
	set_value(2000);
        set_weight(5);
        set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
        set_property("enchantment",5);
	set_item_bonus("spell damage resistance",10);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
   if((int)ETO->query_highest_level() < 25) {
   tell_object(ETO,"%^BOLD%^%^BLACK%^The boots reject you.");
   return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls the boots on and clasps the buckles.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull the boots on and clasp the buckle.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes the boots and unclasps the buckles.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the boots and unclasp the buckle.");
	return 1;
}
