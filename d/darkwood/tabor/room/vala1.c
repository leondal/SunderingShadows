//updated by Circe 6/2/04 with color, etc.
// Vala Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// vala1.c

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
You are on %^BOLD%^%^CYAN%^Vala Street %^RESET%^just east of %^YELLOW%^Caerveron Square%^RESET%^.  From here you
can see the %^YELLOW%^large statue %^RESET%^in the center of the square and to the northeast,
you can see the steeple of the grand %^YELLOW%^Cathedral %^RESET%^of %^BOLD%^%^CYAN%^Saint Vala%^RESET%^, a church that
dwarfs the rest of the buildings in the town.

%^BOLD%^%^CYAN%^Vala Street %^RESET%^continues to the northeast.
%^YELLOW%^Caerveron Square %^RESET%^is to the west.
TABOR
    );
  set_exits(([
    "west" : ROOMDIR+"square",
    "northeast" : ROOMDIR+"vala2"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city mingles "+
     "with the fragrance of incense.");
  set_items(([
    "cathedral" : "The cathedral is built in the antique style, and is "+
       "very solid looking.",
    "statue" : "From here you can make out the statue of a king who "+
       "faces the east, towards you."
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

