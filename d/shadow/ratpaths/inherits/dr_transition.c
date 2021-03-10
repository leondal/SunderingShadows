#include <std.h>
#include "../common.h"

inherit DEEPROAD;

void create(){
    ::create();
    set_light(-1);
    set_property("no teleport", 1);
    set_long(query_long() + "One end of this tunnel has fallen and is blocked with foliage. Hole in the wall leads to the underpaths.");
    set_listen("default", "Earth silences all distant sounds");
}
