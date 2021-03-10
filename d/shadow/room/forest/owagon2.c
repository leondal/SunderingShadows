
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "south":FORESTDIR+"owagon1",
               "northeast":FORESTDIR+"owagon3",
               ]));


}

