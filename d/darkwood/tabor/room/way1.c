//updated by Circe 6/2/04 with color, etc.
// Wizard's Way, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// way1.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_terrain(CITY);
  set_travel(DIRT_ROAD);
  set_light(2);
  set_name("Wizard's Way, Tabor");
  set_short("Wizard's Way, Tabor");
  set_long(
@TABOR
%^BOLD%^Wizard's Way, Tabor%^RESET%^
This is the %^CYAN%^Wizard's Way%^RESET%^, a broad, but fairly disused road leading up a 
steep hill to what anyone can see is a %^CYAN%^Wizard's Tower %^RESET%^on the summit.  To 
the south, you can see this road intersect with another which you can 
see goes from east to west though the city, as well as leaving the city 
and winding off into %^GREEN%^Darkwood Forest %^RESET%^to the east.

%^CYAN%^Wizard's Way %^RESET%^continues to the north.
An intersection is to the south.
TABOR
    );
  set_exits(([
    "north" : ROOMDIR+"way2",
    "southwest" : ROOMDIR+"gwy1"
  ]));
  set_items(([
     ({"tower","wizard's tower","wizards tower"}) : "The lonely tower "+
        "standing on the hill occasionally lights with strange colors "+
        "flickering through its windows."
  ]));
  set_listen("default","You hear muffled rumbles of thunder.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

