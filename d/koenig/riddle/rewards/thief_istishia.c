//thief_auril.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("bandana");
	set_id(({ "bandana", "bandana of the creeping tides" }));
	set_short("%^RESET%^%^CYAN%^Bandana of the %^BOLD%^Creeping%^RESET%^%^CYAN%^ Tides%^RESET%^");
	set_obvious_short("A teal bandana");
	set_long(
@AVATAR
%^CYAN%^Made of fine silk, this bandana takes on a pale teal hue.  Ripping bands of %^BOLD%^aquamarine%^RESET%^%^CYAN%^ travel across the surface of the silk, mimicing the effect of light on the sea.  The bandana's shape is a versitile one, allowing for the wearer to choose how they wish to wear it.  Typically one uses the excess fabric of the bandan to cover their entire head, while the ends are tied back, at the base of their neck.  Though in recent years many have began to adopt the fashion of wearing the bandana as a headband, to keep their hair back from their forehead, and their heads bear.   The silk posses a cool almost clamy feel to it, and seems like it would keep anyone comfortable and cool even during the hottest days.

AVATAR
	);
	set_lore(
@AVATAR
The Bandana of the Creeping Seas came into use by a band of  pirates that sailed the seas, plundering ships.  Istishia is considered to be the patron god of pirates, as well as anyone else who makes their way of life on the sea.  The pirates sailed on an infamous vessel named the Bawdy Sirine, and were known to be able to sneak up on ships from seemingly out of no where.  The pirates they said, after each raid paid their proper respect to their patron god, and made sure to return his portion of the "booty" to the seas. 

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unties the bandana from their head",ETO);
	tell_object(ETO,"%^CYAN%^You remove the silk bandana, though tuck it away in a safe spot");
	return 1;
}
