//mage_mystra.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the seven stars");
	set_id(({ "robe", "robe of the seven stars" }));
	set_short("%^RESET%^%^BLUE%^Robe of the %^BOLD%^%^WHITE%^Seven Stars%^RESET%^");
	set_obvious_short("A midnight blue robe");
	set_long(
@AVATAR
%^BLUE%^Midnight blue cotton is used in the creation of this simple robe.  The robe is cut with long sleeves that are sewn closer to the body than most other robes, but are far from being tight.  It seems that the sides of the robes fold over each other and one can button it closed with well-concealed %^RESET%^silver buttons%^BLUE%^.  Trimming the sleeves and the collar of this robe is a %^BOLD%^%^WHITE%^white cotton%^RESET%^%^BLUE%^ border with a starburst-like pattern woven into it.  Looking long enough, you notice that there are seven different images of starburst that run in a continuous pattern.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of the Seven Stars was crafted by the clergy of Mystra for the faithful.  When two elves unleashed a spellbattle inside the Mother of All Magic's temple, not only the knowledge of how to craft these robes was lost, but also a good number of acolytes.  Insult to injury was added when, after the smoke cleared, the temple was left in ruins.  The Mystrans are still counting their losses to this day.  Not only of spell lore or of wizard's diaries, but also those of the faithful that perished in the attack.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BLUE%^You slip off the robes, doing your best to keep care of such a sacred garment.");
	return 1;
}
