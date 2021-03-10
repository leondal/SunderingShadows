
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "southeast":FORESTDIR+"owagon32",
               "northeast":FORESTDIR+"owagon31",
               "west":FORESTDIR+"owagon29",
               ]));


}

