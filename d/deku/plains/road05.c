#include <std.h>
inherit "/d/deku/plains/road01i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road06",
        "south" : "/d/deku/plains/road04"
   	]));
}
