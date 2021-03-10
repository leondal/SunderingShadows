//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("white leather boots");
	set_id(({ "boots", "boots of the lunar path" }));
	set_short("%^BOLD%^%^WHITE%^Boots of the %^CYAN%^Lunar%^WHITE%^ Path%^RESET%^");
	set_obvious_short("A pair of white leather high boots");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Soft white leather has been crafted into these high boots.  The boots come up past one's knees, and look as if they might provide some protection.  The soles of the boots are made from a thick by plyable %^RESET%^grey %^BOLD%^leather.  The tops of the boots fold down about five inches, and have been finished with a %^CYAN%^silvery blue%^WHITE%^ rectangular boarder.

AVATAR
	);
	set_lore(
@AVATAR
The Boots of the Lunar Path are rumored to be used by the faith of Selune.  There is a legend about that the boots are blessed by the Goddess herself to allow one to travel from one area of moonlight to the next in an instant.  There is a legend of a rogue of Selune, Methesan, who was able to escape a band of Maskians by the use of this ability.  The followers of Mask, it is said, were after Methesan because he had managed to stolen back from the church a holy relic of the faith of Selune.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" pulls themselves out of a pair of high white boots with ease.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You pull yourself out the boots with ease.");
	return 1;
}
