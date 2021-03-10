#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road33",
        "south" : "/d/deku/plains/road31"
   	]));
}
