//mage_torm.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the golden lion");
	set_id(({ "robe", "robe of the golden lion" }));
	set_short("%^BOLD%^%^WHITE%^Robe of the %^YELLOW%^Golden Lion%^RESET%^");
	set_obvious_short("A white cotton robe");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^This is a long, flowing robe made of fine grade cotton.  The cotton is a brilliant white shade that seems to resist any dirt.  Stiched across the back of the robes is a detailed image of a %^YELLOW%^golden lion%^WHITE%^.  %^BLUE%^Blue silk%^WHITE%^ accents finish the hem and cuffs of the robes.  Woven into the cotton is the image of Torm the True's holy symbol over the left breast.  Deep pockets lined with %^BLUE%^blue silk%^WHITE%^ finish off the details of this robe.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Golden Lions are robes that are reserved for a special sect in Torm's faith of mages.  The mages are committed to Torm's philopsophy and uphold his charge to the last letter.  Typically Abjurers fill out this sect, but as Torm is a faith that engages in many battles, invokers, transmuters, and summoners have also begun to fill the ranks of this sect.  It is seen as a great honor and blessing to be rewarded with these robes.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^YELLOW%^You slip the robe off.");
	return 1;
}
