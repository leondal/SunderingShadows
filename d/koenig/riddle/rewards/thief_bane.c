//thief_bane.c - reward for Riddle Quest.  Thanks to Shar for 
//the item description!  Circe 1/19/04
#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("bloodstone crown");
	set_id(({ "crown", "bloodstone crown", "tyrant's crown" }));
	set_short("%^BOLD%^%^GREEN%^The T%^RED%^y%^GREEN%^r%^RED%^a%^GREEN%^n%^RED%^t%^GREEN%^'%^RED%^s%^BLACK%^ Crown%^RESET%^");
	set_obvious_short("A bloodstone crown");
	set_long(
@AVATAR
%^BOLD%^%^GREEN%^Carved from bloostone, this crown features three points.  The bloodstone has a rich green hue to it with flecks of %^RED%^red%^GREEN%^ that dots it's surface.  The stone has been polished and sanded to a smooth finish, giving the crown a noble air to it.  The center point of the crown is the largest with two smaller points of equal size flanking it.  %^BLACK%^Blackened iron%^GREEN%^ has been used to form the base of the crown and to reinforce the bloodstone body.  Chips of bloodstone seem to be missing from sections of the crown, giving it an ancient feeling. 

AVATAR
	);
	set_lore(
@AVATAR
The Tyrant's Crown is said to have been the crown used by Lord Methergarn, the first tyrant of the lands during the thirtyith decade of Shadow's history.  Lord Methergarn came from the barbarian tribes to the north and settled in the virgin woods that use to cover the lands of Shadow.  It is said that Methergarn carved a brutal and bloodthirsty empire from the native humans who lived here and had many battles with the elves who lived in the woods.  Through an iron and bloody fist, Lord Methergarn was able to proclaim himself King of Vexragan, an ancient city that was once where the Shadow Desert is now.  Like with most tyrant's, Lord Methergarn's reign was brief, but violent, and one that has left many scars still present to this day.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" removes the bloodstone crown.",ETO);
	tell_object(ETO,"%^BOLD%^%^GREEN%^You remove the crown from your head, but can't help shake the feeling of superiority that the crown granted you.");
	return 1;
}
