#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road19",
        "east" : "/d/deku/plains/road21"
   	]));
}
