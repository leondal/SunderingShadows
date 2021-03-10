inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the western section of the keep's courtyard.  To the west
you can see an entrance to a building.
MILT
);
set_exits((["north"  : ROOMS + "keep4",
            "south"  : ROOMS + "keep2",
            "west"   : ROOMS + "barracks",
            "east"   : ROOMS + "keep6",
]));
}
