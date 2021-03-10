//mage_silvanus.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("shirt of the stag");
	set_id(({ "shirt", "shirt of the stag" }));
	set_short("%^RESET%^%^GREEN%^Shirt of the %^ORANGE%^Stag%^RESET%^");
	set_obvious_short("A deerhide shirt");
	set_long(
@AVATAR
%^ORANGE%^This shirt is made from the hide of a deer.  The hide still retains its soft lusterous pelt, giving a healthy image to the shirt.  %^WHITE%^White%^ORANGE%^ spots can still be seen across the hide.  The shirt is cut in a fashion typical of any other shirt.  The sleeves are short, probably as to not get in the way.  Five buttons are centered down the opening in the front.  The opening stops at mid chest.  The buttons look to be made of horn and carved to look like a stag deer, with horns and all!  The shirt looks comforting and almost inviting.

AVATAR
	);
	set_lore(
@AVATAR
The Shirt of the Stag is utilized by the mages who follow Silvanus, the Oak Father.  The mages wish to live at harmony with nature, and in some ways are the protecters of the woods, flora and fauna.  Since they care not to waste anything if possible, when a deer is hunted for food they make use of its hide and horns.  The stag is a sacred animal of Silvanus, and some say that by wearing its hide they carry the blessings of Silvanus with them.  Even so, nature has a way of dealing with those who abuse its bounties.  

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^ORANGE%^You slip out of the shirt.");
	return 1;
}
