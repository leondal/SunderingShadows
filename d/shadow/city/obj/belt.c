//Giving pouches an update look - Cythera 4/05
#include <std.h>
inherit PARMOUR;

void create(){
    	set_id( ({"belt","utility belt"}) );
    	set_name("small utlity belt");
		set_short("%^BOLD%^%^BLACK%^A small %^RESET%^gray%^BOLD%^%^BLACK%^ utility belt%^RESET%^");
    	set_long("%^RESET%^%^ORANGE%^This %^BOLD%^%^BLACK%^leather utility belt %^RESET%^%^ORANGE%^has various pouches, "+
		"buckles and loops. The buckles seem purely for aesthetic purposes, while the pouches and loops could likely "+
		"hold some small treasure or a vial or two. The belt itself is %^BOLD%^%^BLACK%^dark gray "+
		"%^RESET%^%^ORANGE%^and soft, and looks a bit %^WHITE%^worn%^ORANGE%^. Despite its age, the belt "+ 
		"could still be very useful.%^WHITE%^");
		set_weight(3);
    	set_value(3);
    	set_max_internal_encumbrance(5);
		set_property("enchantment",1);
		set_limbs(({"waist"}));
		set_type("clothing");
}