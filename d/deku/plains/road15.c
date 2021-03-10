#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "east" : "/d/deku/plains/road14",
        "north" : "/d/deku/plains/road16"
   	]));
}
