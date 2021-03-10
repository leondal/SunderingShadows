//updated by Circe 6/2/04 with color, etc
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math9.c

#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create() {
  ::create();
  set_light(2);
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are on a fairly steep upward slope on Mount Tabor, above the town of
Tabor.  To the north, it looks like the road both gets more narrow and
starts to wind up the hill towards the %^YELLOW%^castle %^RESET%^on the top.  To the south,
you see the slope become gentler and the town spreads out before you in
that direction.  A %^GREEN%^grassy lot %^RESET%^opens to the west with scattered 
%^BOLD%^stones %^RESET%^hinting at future progress.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south.
DAI
    );
  set_exits(([
    "south" : ROOMDIR+"math8",
    "north" : ROOMDIR+"math10",
    "west" : ROOMDIR+"instruments"
  ]));
  set_listen("default","You hear the muted sounds of a large town to the south.");
  set_smell("default","The air here is clean with only faint "+
     "scents of the town below.");
  set_items(([
    "town" : "You can easily see the buildings of the town from here.",
    "castle" : "Caer Tabor is a rather imposing looking structure from here."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

