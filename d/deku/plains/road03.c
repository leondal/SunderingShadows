#include <std.h>
inherit "/d/deku/plains/road01i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road04",
        "south" : "/d/deku/plains/road02"
   	]));
}
