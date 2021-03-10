//updated by Circe 6/2/04 with color, etc
// Wizard's Way, Tabor
// Thorn@ShadowGate
// 010205
// Tabor
// way2.c

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
steep hill towards a tall %^CYAN%^tower %^RESET%^on the summit.  To the south, 
you can see this road eventually intersect with another. At this 
height, you can get a good look at %^GREEN%^Darkwood Forest %^RESET%^to 
the east, and can overlook a great deal of town to the southwest.  

An occasional flash of %^BOLD%^%^RED%^m%^RESET%^%^ORANGE%^u%^YELLOW%^l%^GREEN%^t%^CYAN%^i%^BLUE%^c%^RESET%^%^BLUE%^o%^MAGENTA%^l%^BOLD%^o%^WHITE%^r%^RED%^e%^YELLOW%^d lightning %^RESET%^seems to be emanating from 
the %^CYAN%^tower %^RESET%^on the hill.

%^CYAN%^Wizard's Way %^RESET%^continues to the north and south.
TABOR
    );
  set_exits(([
    "south" : ROOMDIR+"way1",
    "north" : ROOMDIR+"way3"
  ]));
  set_items(([
     ({"tower","wizard's tower","wizards tower"}) : "The lonely tower "+
        "standing on the hill occasionally lights with strange colors "+
        "flickering through its windows.",
     ({"forest","darkwood forest"}) : "%^GREEN%^The thick trees of the "+
        "Darkwood Forest cover the land to the east.  You can see a narrow "+
        "pathway that occasionally breaks through the lines of trees."
  ]));
  set_listen("default","You hear rumbles of thunder.");
  set_smell("default","The slightly rank scent of a busy city "+
    "mingles with the fragrance of ozone.");
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

