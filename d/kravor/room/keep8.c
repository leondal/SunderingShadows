inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the eastern section of the keep's courtyard.  To the east
you see a crumbling structure long since abandoned by its owners.
MILT
);
set_exits((["south"  : ROOMS + "keep7",
            "west"  : ROOMS + "keep6",
            "east"  : ROOMS + "stable",
            "north" : ROOMS + "keep9",
]));
}
