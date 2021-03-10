inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the northwest corner of the keep's courtyard.  To the
northwest you can see an entrance into one of the keep's towers.
MILT
);
set_exits((["south" : ROOMS + "keep3",
            "east" : ROOMS + "keep5",
]));
}
