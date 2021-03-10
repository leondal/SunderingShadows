//mage_selune.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("lunar waistcoat");
	set_id(({ "waistcoat", "coat", "lunar waistcoat", "the lunar waistcoat" }));
	set_short("%^BOLD%^%^WHITE%^The %^CYAN%^Lunar%^WHITE%^ Waistcoat%^RESET%^");
	set_obvious_short("A white waistcoat");
	set_long(
@AVATAR
%^BOLD%^Crafted out of linen, this soft white waistcoat is a striking piece of clothing.  The coat is fitted through the torso area, then flares out from the waist.  The linen still remains crisp and retains its strength.  The front of the coat features silver clasps in the shape of crecent moons that interlock together.  The lower portion of the coat, called the peplem, has soft pleats to reduce the bulkiness that such fabric would cause.  Slender sleeves that come to the wrists give the coat a lavish feeling.  A high collar studded with moonstones finishes off this coat.  

AVATAR
	);
	set_lore(
@AVATAR
The Lunar Waistcoat was made for Elemaralan Illithoughen, an elven warrior/mage of the Moonmaiden, by a half-elven priestess.  Though cautioned against falling for the priestess, due to her shortened lifespan and muddled bloodline, Elemaralan could not help it.  The priestess, Wyndolyn Silvertouch, was a skilled seamstress and crafted the waistcoat for her love to wear in his battles.  It is said that Elemaralan met his end at the hand of a band of drow.  Wyndolyn is said to have had a vision of Elemaralan's troubles and gathered the clergy to go try to resuce him.  Sadly, she was too late.  She kept his waistcoat in rememberance of the love she had lost.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^You slip out of the waistcoat");
	return 1;
}
