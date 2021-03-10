//mage_eldath.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of still pools");
	set_id(({ "robe", "robe of still pools" }));
	set_short("%^BOLD%^%^GREEN%^Robe of %^BLUE%^Still Pools%^RESET%^");
	set_obvious_short("A blue linen robe");
	set_long(
@AVATAR
%^BOLD%^%^BLUE%^These robes are simple in form, looking almost like any other normal robe that can be found.  The soft blue linen has been worn to a smooth finish.  Woven into the fabric is an image about the size of your index finger of a waterfall plunging into a still pool.  The small image is repeated innumerable times, covering the entire garment.  Bands of %^BOLD%^%^GREEN%^fern green%^BLUE%^ cotton trim the sleeves and hem of the robe.  The robe seems to have been lined in %^GREEN%^fern green%^BLUE%^ cotton as well, giving it a comforting feeling.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Still Pools is a blessed robe that most of Eldathian's faithful wear.  The Mother of Water is generous with her gifts, as long as they uphold her dogma.  The robes are said to be found laying at the base of a waterfall or in a quiet pool at the most unexpected times.  The faithful who have been blessed with these robes are highly respected in the faith.  It is said though that those who try to bend Eldath's will to their own will find that the robes will rot away right before their eyes.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLUE%^You slip out of the robes.");
	return 1;
}
