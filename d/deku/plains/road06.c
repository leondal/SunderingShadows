#include <std.h>
inherit "/d/deku/plains/road01i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road07",
        "south" : "/d/deku/plains/road05"
   	]));
}
