inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the center of the keep's courtyard.  Gazing around you,
you see the once mighty walls and structures of the keep now falling
into ruins.
MILT
);
set_exits((["north"  :  ROOMS + "keep5",
            "south"  :  ROOMS + "keep1",
            "west"   :  ROOMS + "keep3",
            "east"   :  ROOMS + "keep8",
]));
}
