#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road15",
        "north" : "/d/deku/plains/road13"
   	]));
}
