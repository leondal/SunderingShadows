//updated by Circe 6/2/04 with color, etc
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math11.c

#include <std.h>
#include "../include/tabor.h"

inherit CROOM;

void create() {
  set_monsters( ({ "/d/darkwood/tabor/mon/guard" }), ({random(3)+1}) );
  monster_party(40);
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are quite near the fortress of %^YELLOW%^Caer Tabor %^RESET%^now.  The road is quite
narrow here but still probably enough to get a good sized wagon though. 
However, the roadsides approach the edge of the slope and there is a
sizable drop to each side.  To the southeast, you see the road round a
bend, leading down towards the town.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the northwest and southeast.
DAI
    );
  set_exits(([
      "southeast" : ROOMDIR+"math10",
      "northwest" : ROOMDIR+"math12"
  ]));
  set_listen("default","You hear the faint sounds of a large town to the south.");
  set_smell("default","The air here is clean with only faint "+
     "scents of the town below.");
  set_items(([
    "town" : "You can see the buildings of the town from here.",
    "castle" : "You see the thick, ancient walls of the fortress loom above you."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

