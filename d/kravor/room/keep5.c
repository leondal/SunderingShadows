inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in front of the main building of the keep.  Gazing upon the
crumbling structure, you notice that mother nature has not been kind
on its once impenetrable walls.
MILT
);
set_exits((["west"  : ROOMS + "keep4",
            "south" : ROOMS + "keep6",
            "east"  : ROOMS + "keep9",
]));
}
