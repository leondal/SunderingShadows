
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "south":FORESTDIR+"owagon9",
               "east":FORESTDIR+"owagon11",
               ]));
}

