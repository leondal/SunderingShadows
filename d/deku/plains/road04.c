#include <std.h>
inherit "/d/deku/plains/road01i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road05",
        "east" : "/d/deku/plains/road03"
   	]));
}
