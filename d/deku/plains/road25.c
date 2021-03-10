#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road26",
        "east" : "/d/deku/plains/road24"
   	]));
}
