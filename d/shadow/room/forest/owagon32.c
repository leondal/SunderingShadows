
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southeast":FORESTDIR+"owagon33",
               "northwest":FORESTDIR+"owagon30",
               ]));


}

