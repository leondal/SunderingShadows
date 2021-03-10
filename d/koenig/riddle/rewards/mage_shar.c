//mage_shar.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of the obsidian disk");
	set_id(({ "robe", "robe of the obsidian disk" }));
	set_short("%^RESET%^%^MAGENTA%^Robe of the %^BOLD%^%^BLACK%^Obsidian Disk%^RESET%^");
	set_obvious_short("A violet silk robe");
	set_long(
@AVATAR
%^MAGENTA%^Crafted from a thin silk, these violet-colored robes look as if they would not offer much protection.  The thin silk looks almost sheer, and - if under the right lighting conditions - they more than likely would be.  A repeating pattern of interlocked %^BOLD%^%^BLACK%^black disks%^RESET%^%^MAGENTA%^ covers the robe.  Bits of metallic threads woven into the disks give them a slick, wet appearance.  A violet cord allows for the robes to be tied closed.  The sleeves of the robe are full and flowing, much like the robes themselves.

AVATAR
	);
	set_lore(
"Amerian Melforqurar was a not-so-famous mage of Shar, which was just "
"the way she liked it.  Amerian detested fame, for it brought too much "
"attention to her and what she felt was her Mistress' charge.  Amerian "
"managed to pass herself off as a simple woman, with little or no talents "
"whatsoever.  Using her charm and sultry looks she managed to woo a temple "
"guard of Selune into beliving that she loved him.  The two married and "
"seemed to be the envy of many for their perfect life.  Amerian only "
"performed her 'duties' as a wife for the honor of her Mistress and to "
"try to gain access into the faith of Selune.  Amerian was able to provide "
"fellow Sharrans with information on the temple of Selune, the layouts, secrets "
"her husband showed her, and even their defenses, in preparation for a "
"crippling strike.  Her plan would have worked if it had not been for a "
"paladin of Selune by the name of Tidus O'torfar, who was able to see "
"past the illusions that Amerian surrounded herself in.  Amerian paid for "
"her deceit with her life, but became a martyr to all Sharrans for her "
"total dedication to the faith. Her robes, said to be infused with her "
"blood, are seen as a holy artifact in the faith that only the worthy are allowed to wear."
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^MAGENTA%^You slip off the robes, but know the time to strike against the Selunites will come again soon!");
	return 1;
}
