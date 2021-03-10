//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("green hat");
	set_id(({ "hat" }));
	set_short("%^RESET%^%^GREEN%^Hat of Greenleaves%^RESET%^");
	set_obvious_short("A forest green felt hat");
	set_long(
@AVATAR
%^GREEN%^Forest green felt has been used to make this hat.  The slender hat's shape is almost triangular in shape.  The front of the hat tapers to a narrow point that fades into the rounded back.  The brim of the hat is turned up slightly to give a view of contrasting %^BOLD%^leaf green felt%^RESET%^%^CYAN%^. A %^BOLD%^%^RED%^bright red%^RESET%^ feather juts out of the hat.

AVATAR
	);
	set_lore(
@AVATAR
Hat of Greenleaves is named after the famed rogue of Mielikki who preyed on rich merchants, noblemen and cruel bandits in the forests of Deku.  Greenleaves, as how the rogue was only known as, was easily recognized by his stylish green hat with red plume.  As Greenleaves' fame grew many followers of Mielikki began to adopt a similar style of hat to further help hide the true Greenleaves (as many who idolized Greenleaves).   Greenleaves proved to be a large thorn in the side of many nobles on Deku, so much that even today uttering his name is known to send a few of the nobles in to a furry.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" slips off a stylish green felt hat, taking care not to crush the %^RED%^%^BOLD%^feather%^RESET%^.",ETO);
	tell_object(ETO,"%^GREEN%^You slip the hat off, but take care to not crush the feather.");
	return 1;
}
