//mage_mielikki.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("jerkin of the autumn");
	set_id(({ "jerkin", "jerkin of the autumn" }));
	set_short("%^RESET%^%^GREEN%^Jerkin of the %^RED%^A%^ORANGE%^u%^YELLOW%^t%^RESET%^%^RED%^u%^ORANGE%^m%^YELLOW%^n%^RESET%^");
	set_obvious_short("A leaf pattern jerkin");
	set_long(
@AVATAR
%^GREEN%^Tooled out of a soft green leather, this jerkin is not like most other jerkins.  Typically a jerkin is sleeveless and only comes to the waist.  This jerkin is indeed sleeveless but falls down to the mid thigh.  A stiff collar stands away from the jerkin and runs down the center of the garment.  Leather cording allows for the jerkin to be laced tight to protect one from the elements.  A heavy gathering of leaves - yes, real leaves - starts at the bottom edge of the jerkin and works its way up, thinning out as they reach higher.  The leaves look as if they were collected during the autumn and bear the %^RED%^c%^ORANGE%^o%^YELLOW%^l%^RESET%^%^RED%^o%^ORANGE%^r%^RED%^s%^GREEN%^ of the fall.  The leaves seem to be as soft and supple as the day they first turned to their brilliant colors.

AVATAR
	);
	set_lore(
@AVATAR
The Jerkin of the Autumn is woven by the dryads from the gathering leaves each autumn.  Dryads revere and worship the Lady of the Forest as their protector and patron.  Infusing the jerkin with the vitality of the lands, the dryads bless these jerkins to stay supple and strong.  Only those the dryads feel they can fully trust will ever recieve such a blessing from the Unicorn Goddess.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^GREEN%^You slip off the jerkin.");
	return 1;
}
