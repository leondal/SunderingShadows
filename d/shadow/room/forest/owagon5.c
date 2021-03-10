
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southeast":FORESTDIR+"owagon4",
               "north":FORESTDIR+"owagon7",
               "west":FORESTDIR+"owagon6",
               ]));


}

