
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "south":FORESTDIR+"owagon23",
               "northeast":FORESTDIR+"owagon27",
               "northwest":"/d/shadow/juran/city/r56"
               ]));


}

