#include <std.h>
inherit "/d/deku/plains/road08i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road10",
        "south" : "/d/deku/plains/road08i"
   	]));
}
