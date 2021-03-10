//mage_xvim.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the black hand");
	set_id(({ "robe", "robe of the black hand" }));
	set_short("%^BOLD%^%^GREEN%^Robe of the %^BLACK%^Black Hand%^RESET%^");
	set_obvious_short("A pleated black robe");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^This robe is made out of cotton, which has been dyed a deep shade of black.  The robe seems to be divided into two sections.  The uppermost, from shoulders to mid-chest is two layers of black cotton that have been quilted.  The quilting adds bulk and warmth to those regions.  Bright %^GREEN%^emerald green%^BLACK%^ piping separates the end of the quilted section with the rest of the robes.  Black cotton has been folded into numerous pleats about two fingers wide.  The pleats hang down past the ankles and have no shape what so ever.  Spreading the pleats apart one finds that the pleats are backed with the same %^GREEN%^emerald green%^BLACK%^ fabric that makes up the piping.  Wide pleated sleeves finish off this impressive robe.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Black Hand is given out to select magi of the Tyrant Lord.  The Lord of Strife recognizes the usefulness of the magi and works to keep them within his fold the best he can, just as his priests are charged to do.  This has led to some major conflicts between the priests and the wizards as to just whom the Tyrant favors.  One reason, some sages say, that the Lord of Strife is active about recruiting magi is that they tend to have a very short life span once they cross the line with the clerics.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^GREEN%^You slip out of the robe.");
	return 1;
}
