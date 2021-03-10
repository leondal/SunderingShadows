//Added Lore - Cythera 4/05
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("sea shell top");
	set_id(({"top","sea shell top","white top","white sea shell top"}));
	set_short("%^BOLD%^%^WHITE%^Sea shell top%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^This top is not for the modest!  Strung on strands of"+
		" pearls, two seashells work to provide some covering to a"+
		" womans chest.  The halter neckline of the top works to "+
		"only emphasize a womans decollete instead of conceal, as"+
		" any sane woman would.  The milky white pearls give a lavish"+
		" feel to this top.  Another strand of pearls encircles ones"+
		" body just under the bust.  Fringe made of pearls fall about"+
		" the midriff, hanging almost down to the navel in the center"+
		" and then angling up to only a few inches.  The inside of the"+
		" shells are lined with silk padding, to give plenty of comfort"+
		" to a woman and to prevent any cuts.");
	set_size(2);
	set_type("clothing");
	set_weight(2);
	set_value(80);
	set_property("enchantment",3);
	set_limbs(({"torso"}));
	set_wear((:TO,"wearme":));
	set_lore("A favorite of sirens the seashell "+
		"top has quickly become a highly prized top,"+
		" usually by entertainers, courtesans and women"+
		" who delight in using their bodies to get what "+
		"they want.  Perhaps not to oddly though, followers"+
		" of Istishia have come to start wearing similar tops,"+
		" trying to mold themselves after The Lady of Singing "+
		"Waters. Though, thankfully, this has only caught on with"+
		" the younger followers and not the older ones.");
	set_property("lore",8);

}

int wearme(string str)
{
	if((string)ETO->query_gender() != "female") {
		tell_object(ETO,"You don't have the right body for this"+
		" cute little top.");
		return 0;
	}
		tell_object(ETO,"%^BOLD%^You slip the top over your head"+
			" and under your bust, and cant help but feel a bit"+
			" exposed.  You feel the urge to %^CYAN%^bounce%^WHITE%^");

    return 1;
}

void init()
{
	::init();
	add_action("bounce","bounce");
}

int bounce(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed() || ETO->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if((string)ETO->query_gender() == "female" && query_worn() && !str) {
		write("%^BOLD%^You bounce about happily in your white"+
		" sea shell top.");
		say("%^BOLD%^"+ETO->query_cap_name()+" bounces around"+
		" enticingly in "+ETO->query_possessive()+" white sea"+
		" shell top.");
		return 1;
	}
}

