#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
   set_obvious_short("A black leather belt");
	set_name("Black Belt");
	set_id(({"belt","black belt","shadow belt"}));
	set_short("%^BOLD%^%^BLACK%^Black Belt%^RESET%^");
	set_long(
	"%^BOLD%^%^BLACK%^This is a black leather belt with a tarnished silver buckle."+
	" It doesn't appear to have been affected by the shade and is"+
	" rather ordinary."
	);
	set_size(2);
	set_value(10);
	set_cointype("silver");
	set_weight(1);
	set_type("clothing");
	set_limbs(({"waist"}));
	set_property("enchantment",2);
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	tell_object(ETO,"You put the belt around your waist and buckle it.");
	tell_room(environment(ETO),""+ETO->query_cap_name()+" puts the"+
	" belt around "+ETO->query_possessive()+" waist and buckles it.",ETO);
	return 1;
}

int removeme()
{
	return 1;
}
