//Added Lore Cythera 4/05
// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int FLAG;

void create()
{
	::create();
	set_name("ranger leggings");
	set_id(({"leggings","green leggings","ranger leggings"}));
        set_short("%^RESET%^%^GREEN%^R%^ORANGE%^a%^GREEN%^ng%^ORANGE%^e%^GREEN%^r leggings%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A pair of leather leggings%^RESET%^");
	set_long(
	"%^BOLD%^%^WHITE%^The leggings are made of soft but durable"+
        " %^ORANGE%^leather%^BOLD%^%^WHITE%^ material. They have been dyed various shades of"+
	" %^RESET%^%^ORANGE%^brown%^BOLD%^%^WHITE%^ and "+
	"%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^e"+
	"%^BOLD%^n%^WHITE%^ to blend in with the forest. They look like"+
	" they would be very comfortable.%^RESET%^"
	);
	set_weight(5);
	set_value(400);
	set_lore("Crafted by the Swanmays these leggings are given"+
		" to worthy fellow rangers to wear on their quest to "+
		"protect nature.  The leather used for these leggings "+
		"is said to come from a large buck deer that Mielikki "+
		"sends once on the first day of autumn.  While protectors"+
		" of the wildlife, forest, and nature, rangers see a need"+
		" for hunting for food.  It is when the hunting is done "+
		"carelessly or without reason or mercy that a ranger is "+
		"driven to anger.  An ranger wearing these leggings is "+
		"said to feel a closer connection to nature, thanks to the"+
		" blessings of the Lady of the Forest.");
	set_property("lore",11);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_limbs(({"right leg","left leg"}));
    set_type("clothing");
	set_size(-1);
	set_property("enchantment",2);
}

int wearme()
{
        if(ETO->query_level() < 15) {
		tell_object(ETO,"You must be more experienced to use such"+
		" fine equipment.");
		return 0;
	}
	if(ETO->is_class("ranger") || ETO->is_class("druid")) {
		tell_object(ETO,"%^BOLD%^%^GREEN%^You slip into the"+
		" comfortable leggings.");
		tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+""+
                " slips into the comfortable leggings.",ETO);
        set_item_bonus("dexterity",1);
		return 1;
	}
	else {
                tell_object(ETO,"%^ORANGE%^The leggings are a little scratchy.%^RESET%^");
        set_item_bonus("dexterity",0);
                return 1;
	}
}

int removeme()
{
	tell_object(ETO,"%^GREEN%^You take off your leggings and"+
	" feel rather naked.");
	return 1;
}
