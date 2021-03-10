inherit "/std/room";
#include <std.h>
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep stables");
set_long(
@MILT
You enter what used to be the keep's stables.  Old dust and hay litter 
the floor along with the occasional tufts of grass sprouting up from the
ground.  The wood from the stalls have long since rotted away and all that
is left are the crumbling dividers.
MILT
);
set_exits((["out"  : ROOMS + "keep8",
]));
}
