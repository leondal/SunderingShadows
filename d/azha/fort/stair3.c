// Main Staircase -- Third Floor, Azha Keep
// Thorn@ShadowGate
// 12/19/95
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);    
	set_short("Main Staircase, Third Floor");
  set_long(
@AZHA
%^BOLD%^Third Floor Landing%^RESET%^
	This place is a beautifully decorated area where it is possible to
descend to the lower floors of the Keep.  Here the walls have no
hangings, but rather, the stone itself is decorated in bas-relief.
The images depicted in the stone are those of soldiers, camps, a
fortress and a vast host of what seem to be skeleton soldiers. 
Locked in wild melee, the flickering of torchlight seems to make the
images take on their own life, as if the fight were here and now, and
not in some myth or long gone age.  A well lit hallway is to the
east.  There is a wide portal to the northwest and a normal one to
the southwest.
AZHA
    );
	set_exits(([
	"northwest" : "/d/azha/fort/dining",     
	"southwest" : "/d/azha/fort/kitchen",     
	"down" : "/d/azha/fort/stair2",     
	"east" : "/d/azha/fort/upper4",     
  ] ));     
	set_smell("default","A strong fragrance seems to be coming from the east.");
	set_items(([
		"skeletons" : "These are depictions of undead skeleton soldiers.",
		"fortress" : "One of the towers on this ancient citadel looks familiar.",
	] ));
}
