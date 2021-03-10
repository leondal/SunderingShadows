#include <std.h>
inherit "/d/magic/temples/shar_tunnel2";

void create() {
        ::create();
        set_long(::query_long()+"\n%^BOLD%^%^BLACK%^Just ahead, "+
           "the tunnel seems to open upon a vast subterranean "+
           "lake.\n");
        set_exits(([
           "northwest" : "/d/magic/temples/shar_lake",
           "east" : "/d/magic/temples/shar_tunnel2"           
        ]));
}