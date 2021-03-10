inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the southeast corner of the keep.  To the southeast you
notice an entrance into one of the crumbling towers of the keep.
MILT
);
set_exits((["west"  :  ROOMS + "keep1",
            "north" :  ROOMS + "keep8",
]));
}
