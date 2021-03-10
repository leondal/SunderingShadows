//updated by Circe 6/2/04 with color, etc.
//new exit for temple of Oghma added by Circe 4/13/04
//updated to reflect that Oghma is no longer a deity ~Circe~ 7/21/19
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math4.c

#include <std.h>
//#include "../include/tabor.h"
#include "/d/darkwood/tabor/include/tabor.h"
inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are in Tabor, the capital town of the Kingdom of Tabor. To the
north, you can see a great statue in what looks like a crossroads or
%^YELLOW%^square%^RESET%^.  To the southwest, you can see a large building with a
great deal of smoke coming from a large chimney.  To the west, you 
see a large stone building with people constantly moving in and 
out of it.  It seems to be a focal point for the citizens of this
fair city, while the library lies to the east.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and southeast.
DAI
    );
  set_exits(([
    "southeast" : ROOMDIR+"math3",
    "north" : ROOMDIR+"square",
    "west" : "/d/magic/temples/oghma",
    "east" : ROOMDIR+"lot-library"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The scent of ash from the forge still lingers in the air here.");
  set_items(([
    ({"large building","stone building"}) : "The large stone building "+
       "seems to be quite a popular place.  You see many people coming "+
       "out with books or instruments in hand.",
    "statue" : "You can barely make it out from here, but it looks like a "+
       "golden king on a pedestal.",
    "road" : "%^RESET%^%^MAGENTA%^Mathowvy Road%^RESET%^: North to Tabor, "+
       "south to Azha in Tsarven",
    "library" : "Tabor's library stands in a stone building to the east."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

