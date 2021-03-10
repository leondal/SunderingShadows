#include <std.h>
inherit "/d/deku/plains/road11i";

void create(){
    ::create();
    set_exits(([
        "north" : "/d/deku/plains/road24",
        "west" : "/d/deku/plains/road22"
   	]));
}
