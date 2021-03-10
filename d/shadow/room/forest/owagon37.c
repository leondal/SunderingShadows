
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "northeast":FORESTDIR+"owagon38",
               "west":FORESTDIR+"owagon36",
               ]));


}

