#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_listen("default","Peculiar, the forest is deadly quiet except for a slight sound of a waterfall.");
    set_exits(([
       "west" : "/d/deku/open/lake2",
       "east" : "/d/deku/open/forest46"
    ] ));
    set_items(([
    ] ));
}
