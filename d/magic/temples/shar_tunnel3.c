#include <std.h>
inherit "/d/magic/temples/shar_tunnel2";

void create() {
        ::create();
        set_exits(([
           "northwest" : "/d/magic/temples/shar_tunnel2",
           "east" : "/d/magic/temples/shar_tunnel4"           
        ]));
}