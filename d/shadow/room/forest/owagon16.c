
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "south":FORESTDIR+"owagon15",
               "northeast":FORESTDIR+"owagon17",
               "northwest":FORESTDIR+"owagon18",
               ]));


}

