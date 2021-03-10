//mage_auril.c - reward for Riddle Quest.  Thanks to Shar for coding this item :)
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
	::create();
	set_name("robe of midwinter's night");
	set_id(({ "robe", "robe of midwinter's night" }));
	set_short("%^BOLD%^%^WHITE%^Robes of %^CYAN%^Midwinter's %^BLACK%^Night%^RESET%^");
	set_obvious_short("A sleeveless white robe");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^These robes are fashioned out of brilliant white cotton.  The cotton has been bleached of any color what so ever, leaving it almost a gleaming shade of white.  The robe is sleeveless.  The upper portion of the robe is cut in a jerkin fashion, fitting close to the body.  A deep v neckline plunges down to one's navel.  Lining the inside of the robe is a bushy white fur, that spills over the seams.  A thin %^CYAN%^ice blue%^WHITE%^ cord allows one to lace the robe's opening up, though never all the way.  The lower portions of the robe is cut like a typical robe, made of the same white cotton.  %^CYAN%^Ice blue%^WHITE%^ pipping runs along the seams and hem of the lower portion of the robe.

AVATAR
	);
	set_lore(
@AVATAR
The Robe of Midwinter's Night are sacred robes dedicated and blessed by Auril during the coldest and darkest time of the year, Midwinter's night.  On that night, they say, the faithful of Auril go out to hunt some creature, be it beast or humanoid,  during a snowstorm.  The faithful only wear Auril's cold caress and must use the ice, snow, or cold to kill the creature.  With the blood of the victim, a sacred rite is performed.  If the Frostmaiden is pleased, the robes will be her gift to the faithful.  If not... well, none seems to have lived to tell of what happens if the Ice Queen is not pleased...

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^CYAN%^You slip out of the robes.");
	return 1;
}
