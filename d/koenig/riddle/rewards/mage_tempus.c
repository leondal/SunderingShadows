//mage_tempus.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("battlemage robes");
	set_id(({ "robe", "robe of the battle mage" }));
	set_short("%^RESET%^%^WHITE%^Robes of the %^RED%^Battle %^BOLD%^Mage%^RESET%^");
	set_obvious_short("A steel gray robe");
	set_long(
@AVATAR
These robes are made in two layers.  The uppermost layer, the one that is most seen, features steel gray colored linen woven with metallic threads.  The threads have been knitted together in a chain stitch pattern, looking similiar to chainmail.  In fact the cut of this robe reminds one of a chainmail shirt more than anything, but made of cloth.  Underneath the steel gray robe another robe takes shape.  Soft ivory linen that has been streaked with blotches of %^RED%^crimson%^RESET%^ in a chaotic pattern.  Both robes are cut short, to about the knees, and have elbow length sleeves, perhaps not to be to cumbersome.

AVATAR
	);
	set_lore(
@AVATAR
The Robes of the Battle Mage are used by those select few magi who take up Tempus' cause and use their arcane power to futher the god's goals.  While many belive that the Tempusians abhor or mistrust magic, this is in fact untrue.  Few mages can survive on the battlefield, and in fact that is what has led to such a low number of mages in the Warlord's faith. 

AVATAR
	);
      set_property("lore difficulty",12);
}