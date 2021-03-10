//thief_eldath.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("pale blue cowl");
	set_id(({ "cowl", "cowl of tranquility" }));
	set_short("%^BOLD%^%^CYAN%^Cowl of %^BLUE%^Tranquility%^RESET%^");
	set_obvious_short("A pale blue cotton cowl");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This cowl is made from a slighty coarse weave of linen, dyed a very pale shade of blue.  The cowl  is cut in a way that one can place it over their head and shoulders.  The cowl itself is open, never hiding or obsuring the face of the wearer.  Instead the excess fabric hangs to the side of one's face.  The bottom of the cowl forms a mantle of sorts around the shoulders of the wearer.  The edges of the cowl are finished off with a %^BLUE%^water blue%^CYAN%^ cotton band.

AVATAR
	);
	set_lore(
@AVATAR
The Cowl of Tranquilty comes to us from the faith of Eldath.  It is rumored that the priests of Eldath are granted with a sercret that allows them to weave the very water itself into protective clothing and garb, to always carry a portion of their goddess with them.  The cowl is rumored to calm and quiet even the most chaotic and violent heart, blessing them with Eldath's gentle tranquility.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" removes their cowl with a slight sigh.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You remove the cowl, though find remnants of the tranquilty that filled your heart still lingering.");
	return 1;
}
