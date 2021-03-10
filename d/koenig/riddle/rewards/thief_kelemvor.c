//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NBOOTS;

void create(){
	::create();
	set_name("grey leather boots");
	set_id(({ "leather boots", "grey boots", "boots of the crypt walker","boots"}));
	set_short("Boots of the Crypt Walker");
	set_obvious_short("A pair of dull grey leather boots");
	set_long(
@AVATAR
These soft boots have been made of a dull neutral shade of grey.  The boots are very simple in design, looking like almost any other normal pair of boots.  There does not seem to be any detail on these boots that would put them as something special at first glance.  Looking closer you can see what seems to be a faint faded image of a skeletal hand tooled into the leather of the boots.  The image is so faded and worn that few will even notice it.

AVATAR
	);
	set_lore(
@AVATAR
The Boots of the Cypt Walker are worn by the faithful of Kelemvor who must enter tombs and crypts of undead creatures.  The boots are said to have a blessing added to them by the priests of Kelemvor to offer protection on the unholy ground and to aid one who wears them against the negative energy that the undead draw upon.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes the soft grey leather boots.",ETO);
	tell_object(ETO,"You remove the boots, but keep the safe");
	return 1;
}
