#include <std.h>
#include "../antioch.h"
inherit "/d/common/obj/armour/bracers";

void create()
{
	::create();
   set_obvious_short("bracers");
	set_name("bracers of magi");
	set_short("%^BOLD%^%^RED%^Bracers of Magi%^RESET%^");
	set_id(({"bracers","magi bracers","bracers of magi","Bracers of Magi","magic bracers"}));
   set("lore",
	"These bracers are clearly possessed of some sort of magic, but what that is"+
	" you can't be sure. Special runes have been engraved upon them, and these"+
	" are constantly moving and swirling into new shapes and forms, impossible to"+
	" read. They have obviously been crafted by a mage-smith and imbued with magic."
	);
   set_long("A set of high quality bracers. They look to be well cared for and seem lighter than their heft would indicate.");
	set_value(3000);
	set_property("enchantment",1);
	while(TO->query_property("enchantment") < 1) {
		remove_property("enchantment");
		set_property("enchantment",1);
	}
	set_item_bonus("magic resistance",1);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
	if(ETO->is_class("mage") || ETO->is_class("bard")) {
		if(ETO->query_lowest_level() < 10) {
			tell_object(ETO,"You are not yet experienced enough to use these bracers.");
			return 0;
		}
		tell_object(ETO,"A magical tingle races through your body as you put on the bracers.");
		if(ALIGN->is_evil(ETO)) {
			set_short("%^BOLD%^%^BLACK%^Bracers of Magi%^RESET%^");
		}
		else if(ALIGN->is_good(ETO)) {
			set_short("%^BOLD%^%^WHITE%^Bracers of Magi%^RESET%^");
		}
		return 1;
	}
	else if(ETO->is_class("thief") || ETO->is_class("ranger")) {
		tell_object(ETO,"You cannot seem to utilize the magic within these bracers.");
		return 0;
	}
	else {
		tell_object(ETO,"Your class does not allow you to use these.");
		return 0;
	}
}

int removeme()
{
	tell_object(ETO,"You feel the magic drain from your body as you remove the bracers.");
	set_short("%^BOLD%^%^RED%^Bracers of Magi%^RESET%^");
	return 1;
}
