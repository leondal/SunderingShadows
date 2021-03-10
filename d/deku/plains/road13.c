#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "south" : "/d/deku/plains/road14",
        "east" : "/d/deku/plains/road12"
   	]));
}
