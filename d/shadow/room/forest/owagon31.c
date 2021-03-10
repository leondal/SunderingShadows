
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southwest":FORESTDIR+"owagon30",
               "northeast":FORESTDIR+"owagon39",
               ]));


}

