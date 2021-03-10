
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southeast":FORESTDIR+"owagon25",
               "southwest":FORESTDIR+"owagon26",
               "northeast":FORESTDIR+"owagon28",
               ]));


}

