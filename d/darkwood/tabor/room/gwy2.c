//updated by Circe 6/2/04 with color, etc.
// Gwydion Street and Vala Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// gwy2.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Gwydion Street and Vala Street, Tabor");
  set_short("Gwydion Street and Vala Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Gwydion Street and Vala Street, Tabor%^RESET%^
You are at the intersection of %^BOLD%^%^BLUE%^Gwydion Street %^RESET%^and %^BOLD%^%^CYAN%^Vala Street %^RESET%^in the
royal town of Tabor.  To the northeast, you can see the summit of %^RED%^Mount
Dragon %^RESET%^in the distance topped by the %^CYAN%^Wizard's Tower %^RESET%^of Tabor.  To the
south you can see the great %^YELLOW%^Cathedral of St. Vala %^RESET%^down %^BOLD%^%^CYAN%^Vala Street%^RESET%^.

%^BOLD%^%^MAGENTA%^There is a sign you can look at here.

%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east and west.
%^BOLD%^%^CYAN%^Vala Street %^RESET%^continues to the south.
TABOR
    );
  set_exits(([
    "east" : ROOMDIR+"gwy1",
    "west" : ROOMDIR+"gwy3",
    "south" : ROOMDIR+"vala3"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "sign" : "%^BOLD%^%^CYAN%^Vala Street%^RESET%^: South to %^YELLOW%^"+
             "Cathedral %^RESET%^and %^YELLOW%^Caerveron Square\n"+
	       "%^BOLD%^%^BLUE%^Gwydion Street%^RESET%^: East to %^BOLD%^"+
             "Royal Highway%^RESET%^, west to %^MAGENTA%^Mathowvy Road%^RESET%^",
    "cathedral" : "The cathedral is built in the ancient style, and "+
       "is very solid looking."
  ]));
 }
void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

