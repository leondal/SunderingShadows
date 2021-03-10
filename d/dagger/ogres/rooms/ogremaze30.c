
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
    ::create();
    set_exits(([
"northwest" : ROOMS"ogremaze25",
        "southwest" : ROOMS"ogremaze52",
      "east" : ROOMS"ogremaze31",
      ]));

}
