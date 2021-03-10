// Imperial Northern Highway into Azha
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
//  object ob;
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);
	set_short("Imperial Northern Highway, Azha Province");
  set_long(
@AZHA
%^BOLD%^The Imperial Northern Highway%^RESET%^
	You have stepped onto the northern-most reaches of the fabled
Empire of Tsarven, Jewel of the Southern Realms.  This
highway conveys travellers from the north straight into the heart of
the Empire, to trade and visit.  Even in this rough frontier area,
the high civilization of the Empire is evident from the excellent
conditions of the highway and the tall %^YELLOW%^golden%^RESET%^ obelisk standing by the
side of the road.  To the north, you enter the Northern Realms. To
your east, the west gate of the outpost town of Azha beckons to
you....
AZHA
    );
	set_exits(([
	"northwest" : "/d/tharis/road/wroad30",
	"east" : "/d/azha/town/westgate"
  ] ));
	set_smell("default","You smell the dust of this well worn road.");
	set_items(([
		"obelisk" : "The obelisk is about 30 feet tall, emblazoned with a crescent moon.\n",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "public");
}
