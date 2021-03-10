//ranger_eldath.c - reward for Riddle Quest. Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("eldath hide");
	set_id(({"ivy","armor of ivy","ivy vines","vine armor","hide","tangle","tangle of ivy"}));
	set_short("%^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s "+
         "%^RESET%^%^GREEN%^of %^CYAN%^Peace%^RESET%^");
	set_obvious_short("A tangle of ivy");
	set_long(
@CIRCE
%^GREEN%^This unusual suit of armor appears at first to be nothing more than a tangle of ivy vines.  The vines have no definition on their own, simply forming a shapeless pile on the ground when dropped.  However, as soon as the true owner lifts them, they begin to form and shape themselves to the wearer, making an impenetrable tangle of living armor.  The vines cover the wearer just as a suit of hide armor would, leaving the neck and head free and ending just before the hands and feet.  The ivy would certainly help the wearer blend into forest surroundings, but would give a strange appearance in any city.
CIRCE
	);
	set_lore(
@CIRCE
The armor of ivy was originally created by a ranger named Marius Quietholme, who was dedicated to the Green Goddess.  Legend holds that Marius was once in mortal danger from a band of loggers who were cutting down the forest all around him.  He refused to leave his beloved trees, but when the logger's axe was just about to strike him down, a calmness came over the forest.  Marius fell into a deep sleep, and the loggers were turned to stone where they stood.  He woke up years later, his body covered in ivy, beneath a marvelous stone statue of an axeman.  Since that time, this special armor has been taken as a sign of the Green Goddess's blessing.  
CIRCE
	);
   set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^GREEN%^You let the living ivy drop to the ground, confident that it will grow once more.");
	return 1;
}
