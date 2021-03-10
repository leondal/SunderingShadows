//updated by Circe 6/2/04 with color, etc
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math5.c

#include <std.h>
#include "../include/tabor.h"

inherit CROOM;

void create() {
  set_monsters( ({ "/d/darkwood/tabor/mon/guard" }), ({random(3)+1}) );
  monster_party(40);
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are in the center of Tabor, the capital town of the 
Kingdom of Tabor, north of %^YELLOW%^Caerveron Square%^RESET%^, the crossroads 
of Tabor.  To the west, you see what appears to be a %^ORANGE%^general 
store %^RESET%^that is frequented by the ladies and servants of the 
town.  Across the street is a building with the sign of a 
%^MAGENTA%^writing quill %^RESET%^to the east.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south. 
DAI
    );
  set_exits(([
    "east" : ROOMDIR+"scribe",
    "west" : ROOMDIR+"gstore",
    "south" : ROOMDIR+"square",
    "north" : ROOMDIR+"math6"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city "+
     "lingers in the air.");
  set_items(([
    "statue" : "A golden statue is in the square to the south.  It "+
       "seems to be facing east.",
    "road" : "%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^: North to "+
       "%^YELLOW%^Caer Tabor%^RESET%^, south to %^YELLOW%^Caerveron Square"
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

