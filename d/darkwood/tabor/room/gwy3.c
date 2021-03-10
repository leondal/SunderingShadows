//updated by Circe 6/2/04 with color, etc.
// Gwydion Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy3.c

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
You are on %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^in Tabor just east of %^MAGENTA%^Mathowvy Road%^RESET%^.  Here you
can easily make out the fortress of %^YELLOW%^Caer Tabor %^RESET%^on Mount Tabor to the
north and see %^MAGENTA%^Mathowvy Road %^RESET%^wind up the slope.  To your south, you can
see the great edifice of the %^ORANGE%^Royal Bank %^RESET%^of Tabor and you can enter
through a side entrance here.  A most %^MAGENTA%^unusual building %^RESET%^is just to 
the north, complete with onion-shaped windows and textured walls.  It 
seems to be a tailor of sorts.

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east and west.
TABOR
    );
  set_exits(([
    "east" : ROOMDIR+"gwy2",
    "west" : ROOMDIR+"math7",
    "south" : ROOMDIR+"bank",
    "north" : ROOMDIR+"lot-tailor"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
 }
void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

