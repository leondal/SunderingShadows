#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road34",
        "south" : "/d/deku/plains/road32"
   	]));
}
