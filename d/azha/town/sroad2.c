// Imperial Northern Highway, near Azha
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
grassland as you proceed north on this road.  You can make out hills
only in on the far horizon of this seemingly endless plain.  Only the
%^CYAN%^blue%^RESET%^ of the sky breaks up the monotony of the %^GREEN%^greens%^RESET%^ and %^YELLOW%^yellows%^RESET%^ of
the land.
	There is a stone marker along the side of the road.
AZHA
    );
	set_exits(([
        "north" : "/d/azha/town/sroad1",
  ] ));
	set_smell("default","The dust of this well-travelled road rises to your nose.");
	set_items(([
		"marker" : "The marker reads: Imperial Northern Highway, Azha Province.\n",
	] ));
}
