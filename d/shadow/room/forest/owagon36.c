
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "northwest":FORESTDIR+"owagon35",
               "east":FORESTDIR+"owagon37",
               ]));


}

