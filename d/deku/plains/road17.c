#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "south" : "/d/deku/plains/road16",
        "north" : "/d/deku/plains/road18"
   	]));
}
