
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "east":PASSDIR+"pass16",
               "west":FORESTDIR+"owagon42",
               ]));


}

