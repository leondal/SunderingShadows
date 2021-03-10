//updated by Circe 6/2/04 with color, etc.
// Vala Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// vala3.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Vala Street, Tabor");
  set_short("Vala Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Vala Street, Tabor%^RESET%^
You are standing by the great %^YELLOW%^Cathedral %^RESET%^of %^BOLD%^%^CYAN%^St. Vala %^RESET%^in Tabor. Here you
are looking at the side of the church and see that there is a side
entrance into the building to the southeast.  To the north, you see an
intersection with an east-west street that appears to be the end of %^BOLD%^%^CYAN%^Vala
Street%^RESET%^.

%^BOLD%^%^CYAN%^Vala Street %^RESET%^continues to the north and south.
%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^is to the north.
TABOR
    );
  set_exits(([
    "southeast" : ROOMDIR+"church",
    "south" : ROOMDIR+"vala2",
    "north" : ROOMDIR+"gwy2"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city mingles "+
     "with the fragrance of incense.");
  set_items(([
    "cathedral" : "The cathedral is built in the antique style, "+
       "and is very solid looking."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

