inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the northeast corner of the keep's courtyard.
To the northeast you see an entrance into one of the keep's
towers.
MILT
);
set_exits((["west"  : ROOMS + "keep5",
            "south" : ROOMS + "keep8",
]));
}
