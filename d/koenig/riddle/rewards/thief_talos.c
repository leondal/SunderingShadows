//thief_talos.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("storm boots");
	set_id(({ "boots", "riders of the storm", "grey boots", "storm boots" }));
	set_short("%^BOLD%^%^BLACK%^Riders of the %^RESET%^%^MAGENTA%^S%^BOLD%^%^CYAN%^t%^RESET%^%^MAGENTA%^or%^BOLD%^%^CYAN%^m%^RESET%^");
	set_obvious_short("A pair of grey riding boots");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Hard storm grey leather is used to craft these boots.  The boots rise to mid-shin and feature a hard thick sole, giving them plenty of protection from the elements.  The grey leather you notice has a molted apperance, as if the stormy grey shade is always moving and shifting in hues, from a pale grey to a deep grey-black.  %^CYAN%^Flashes%^BLACK%^ of light can bee seen in the grey swirling mass that turns the clouds a dusky %^RESET%^%^MAGENTA%^violet-grey%^BOLD%^%^BLACK%^.

AVATAR
	);
	set_lore(
@AVATAR
The Riders of the Storm were a band of thugs and rogues dedicated to spread chaos through the lands in Talos' name.  The Riders were said to have rode into towns with the comming storms.  While the violent weather rained down on the cities the riders made sure to pilfer, beat, and do other activities common for thugs.  Before the storm cloudes parted or moved on, the Riders left the city behind.  Buildings broken, people maimed and beaten, and gold and treasures taken.  There is still an old wives' tale that if you see thick black clouds moving in with violent flashes of lighting be warned, for the Riders of the Storm are coming. 

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" removes their storm grey leather boots.  Did you just see the boots flash?",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull your feet from the boots, watching the storm clouds flash in response.");
	return 1;
}
