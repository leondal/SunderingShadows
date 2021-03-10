inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep's courtyard");
set_long(
@MILT
You stand in the southwest corner of the keep's courtyard.  To the
southwest you see the southwest tower of the keep.  The tower appears
to be in shambles. 
MILT
);
set_exits((["north"  : ROOMS + "keep3",
            "east"   : ROOMS + "keep1",
]));
}
