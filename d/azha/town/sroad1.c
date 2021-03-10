// Imperial Northern Highway out of Azha
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(GRASSLANDS);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);
	set_short("Imperial Northern Highway, Azha Province");
  set_long(
@AZHA
%^BOLD%^The Imperial Northern Highway%^RESET%^
	You are on the Imperial Northern Highway, in the northern reaches 
of the empire.  You begin to notice more and more trees and less
grassland as you proceed north, on this road.  Up ahead, towards the
north, you can make out the fortifications of what seems to be a
large outpost town.  The crimson banner on the walls indicates that
even here, the Empire keeps peace and order.
	There is a stone marker along the side of the road.
AZHA
    );
	set_exits(([
        "north" : "/d/azha/town/southgate",
        "south" : "/d/azha/town/sroad2"
  ] ));     
	set_smell("default","You pick up the smell of a nearby town.");
	set_items(([
		"marker" : "The marker reads: Imperial Northern Highway, Azha Province.\n",
	] ));
}
