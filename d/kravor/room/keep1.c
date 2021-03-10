inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand by the gate inside the keep's courtyard.  The courtyard is
in disarray.  Weeds poke up from the cracked cobblestone ground.  Crumbled
debris is strewn all about the courtyard in no particular fashion.
Straight ahead you see the keep's main tower, though in shambles, it is
as imposing as it was in its glory days.
MILT
);
set_exits((["west" : ROOMS + "keep2",
            "south" : ROOMS + "entrance",
            "north" : ROOMS + "keep6",
            "east" : ROOMS + "keep7",
]));
}
