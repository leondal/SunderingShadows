//updated by Circe 6/2/04 with color, etc.
// Gwydion Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy4.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Gwydion Street, Tabor");
  set_short("Gwydion Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Gwydion Street, Tabor%^RESET%^
You are on %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^in Tabor just west of %^MAGENTA%^Mathowvy Road%^RESET%^.  Here you
can easily make out the fortress of %^YELLOW%^Caer Tabor %^RESET%^on Mount Tabor to the
north and see %^MAGENTA%^Mathowvy Road %^RESET%^wind up the slope.  To your south, you can
see the side of what seems to be a %^ORANGE%^healer's shop%^RESET%^, but there is no door
on this street to allow access.  Just north of here stands a %^BOLD%^%^CYAN%^
jewelry store %^RESET%^with a front made entirely of %^BOLD%^%^CYAN%^glass%^RESET%^!

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east and west.
TABOR
    );
  set_exits(([
    "east" : ROOMDIR+"math7",
    "west" : ROOMDIR+"gwy5",
    "north" : ROOMDIR+"lot-jeweler"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city lingers in the air.");
 }
void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

