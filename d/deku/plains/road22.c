#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "south" : "/d/deku/plains/road21",
        "east" : "/d/deku/plains/road23"
   	]));
}
