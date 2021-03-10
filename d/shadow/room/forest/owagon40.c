
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southwest":FORESTDIR+"owagon39",
                "northwest" : "/d/shadow/room/kildare/rooms/roads/eroad15",
               "east":FORESTDIR+"owagon41",
               ]));


}

