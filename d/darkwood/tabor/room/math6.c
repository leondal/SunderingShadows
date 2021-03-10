//updated by Circe 6/2/04 with color, etc.
// Mathowvy Road, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math6.c

#include <std.h>
#include "../include/tabor.h"

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
You are in the center of Tabor, the capital town of the Kingdom of
Tabor.  To the west, you see what appears to be a %^CYAN%^healer's shop%^RESET%^, from
the %^GREEN%^herbs %^RESET%^you see hanging to dry outside.  The %^ORANGE%^Royal Bank of Tabor %^RESET%^is
across the street to the east.  The presence of these two concerns makes
this section of street very busy during the day.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south. 
DAI
    );
  set_exits(([
    "east" : ROOMDIR+"bank",
    "west" : ROOMDIR+"healer",
    "south" : ROOMDIR+"math5",
    "north" : ROOMDIR+"math7"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city "+
     "lingers in the air.");
  set_items(([
    "road" : "%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^: North to "+
       "%^YELLOW%^Caer Tabor%^RESET%^, south to %^YELLOW%^Caerveron Square"
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

