#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road28",
        "east" : "/d/deku/plains/road26",
//      "temple" : "/d/magic/temples/talos",
   	]));
}
