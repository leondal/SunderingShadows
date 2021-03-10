//cave61.c - up to cave26
#include <std.h>
#include "echoes.h"

inherit OGREMINES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"Several large, "+
      "flat rocks have been piled here to make a crude and most "+
      "likely treacherous stairway.  "+
      "They are centered just under a hole high overhead.  To "+
      "the northeast is a passageway that looks like it was once "+
      "part of the dwarves' home.\n");
    add_item("stairway","The large, flat gray rocks piled beneath "+
      "the hole form a crude stairway that despite its ramshackle "+
      "state seems to have stood for some time.");
    set_exits(([
        "up" : ROOMS"cave26",
        "northwest" : ROOMS"cave64",
        "west" : ROOMS"cave60",
        "southwest" : ROOMS"cave56",
        "northeast" : ROOMS"cave65",
   	]));
}
