
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southeast":FORESTDIR+"owagon13",
               "northwest":FORESTDIR+"owagon15",
               ]));


}

