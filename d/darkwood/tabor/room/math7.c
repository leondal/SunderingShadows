//updated by Circe 6/2/04 with color, etc.
// Mathowvy Road and Gwydion Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// math7.c

#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road and Gwydion Street, Tabor");
  set_short("Mathowvy Road and Gwydion Street, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road and Gwydion Street, Tabor%^RESET%^
This is the intersection of %^MAGENTA%^Mathowvy Road %^RESET%^and %^BOLD%^%^BLUE%^Gwydion Street%^RESET%^, the 
main east-west street in Tabor.  To the north, you can see Mount
Tabor and the castle of %^YELLOW%^Caer Tabor %^RESET%^perched on the top, high above
the town.  To the south is the %^MAGENTA%^Mathowvy Road %^RESET%^business district.

%^BOLD%^%^MAGENTA%^There is a sign here you can look at.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the north and south. 
%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^continues to the east and west.
DAI
    );
  set_exits(([
    "east" : ROOMDIR+"gwy3",
    "west" : ROOMDIR+"gwy4",
    "south" : ROOMDIR+"math6",
    "north" : ROOMDIR+"math8"
  ]));
  set_listen("default","You hear the busy sounds of a large town.");
  set_smell("default","The slightly rank scent of a busy city "+
     "lingers in the air.");
  set_items(([
    "sign" : "%^MAGENTA%^Mathowvy Road%^RESET%^: North to "+
       "%^YELLOW%^Caer Tabor%^RESET%^, south to %^YELLOW%^"+
       "Caerveron Square\n"+
       "%^BOLD%^%^BLUE%^Gwydion Street%^RESET%^: East to "+
       "%^RED%^Mount Dragon%^RESET%^, west to the %^GREEN%^"+
       "Fields of Tempus"
  ]));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

