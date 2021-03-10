//updated by Circe 6/2/04 with color, etc.
// Greene Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// greene1.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Greene Street, Tabor");
  set_short("Greene Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Greene Street, Tabor%^RESET%^
You are on %^GREEN%^Greene Street%^RESET%^, Tabor just west of %^YELLOW%^Caerveron Square%^RESET%^.  From
here you can see the %^CYAN%^large statue %^RESET%^in the center of the square and to the
northwest, you can see the %^BOLD%^%^BLACK%^squat gaol %^RESET%^of Tabor, a rather solid, but
grimy looking building. Probably due to the presence of the %^BOLD%^%^BLACK%^gaol%^RESET%^, this
street is not as busy as the rest of the town and the pedestrians seem
to be of a lower class.

%^GREEN%^Greene Street %^RESET%^continues to the northwest.
%^YELLOW%^Caerveron Square %^RESET%^is to the east.
TABOR
    );
  set_exits(([
    "east" : ROOMDIR+"square",
    "northwest" : ROOMDIR+"greene2"
  ]));
  set_listen("default","You hear the muffled sounds of a busy town "+
    "all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "gaol" : "The gaol is not much to look at, but it is most "+
       "defintely a prison.",
    "statue" : "From here you can make out the statue of a king who "+
       "faces the east, away from you."
  ]));
 }
void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

