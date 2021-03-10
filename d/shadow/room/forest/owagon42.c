
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "east":FORESTDIR+"owagon43",
                "west":FORESTDIR+"owagon41",
               ]));


}

