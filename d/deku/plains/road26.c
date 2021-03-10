#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "west" : "/d/deku/plains/road27",
        "east" : "/d/deku/plains/road25"
   	]));
}
