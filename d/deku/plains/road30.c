#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road31",
        "east" : "/d/deku/plains/road29"
   	]));
}
