#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/gauntlets.c";

void create()
{
	::create();
	set_name("gauntlets");
	set_id(({"gauntlets","gauntlets of knighthood","knight's gauntlets","Gauntlets"}));
	set_short("%^BOLD%^%^WHITE%^Gauntlets of Knighthood%^RESET%^");
        set_obvious_short("%^BOLD%^%^WHITE%^Polished steel gauntlets%^RESET%^");
	set_long(
	"%^BOLD%^%^WHITE%^These gauntlets are made of highly polished"+
	" %^CYAN%^steel%^WHITE%^ and are in very good condition. Lightweight"+
        " mithril mesh fills the gaps between the steel plates, adding even "+
        "more protection to these gauntlets.  The steel plates are engraved"+
        " with life-like images of dragons.%^RESET%^"
	);
	set_lore("The Gauntlets of Knighthood are crafted and enchanted "+
		"to only allow the most devoted cavaliers and knights to "+
		"wear them.  Crafted at first by the faithful of Kreysneothosies for their knights, the gauntlets soon came to be "+
		"used by every knightly order across the realms.  The "+
		"rare gauntlets once use to be a common item in the "+
		"regalia of a knight, but with the loss of how they "+
		"were crafted and enchanted these relics have become "+
		"highly prized and treasured.");
	set_property("lore",11);
	set_weight(4);
	set_value(1500);
        set_size(-1);
        set_property("enchantment",2+random(2));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme()
{
        if(ETO->query_lowest_level() < 15) {
		tell_object(ETO,"You are not yet experienced enough to use such equipment.");
		return 0;
	}
	if(ETO->is_class("paladin") || ETO->is_class("cavalier") || ETO->is_class("antipaladin")) {
		tell_object(ETO,"%^BOLD%^You don the Gauntlets of Knighthood"+
		" with great pride.");
		tell_room(ETO,"%^BOLD%^"+ETO->QCN+" dons the"+
		" polished steel auntlets with great pride.",ETO);
		return 1;
	}
	else {
		tell_object(ETO,"Scum such as you is not worthy of these"+
		" gauntlets!");
		return 0;
	}
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^You carefully remove your gauntlets"+
	" and store them safely away.");
	return 1;
}
