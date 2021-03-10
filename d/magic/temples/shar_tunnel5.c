#include <std.h>
inherit "/d/magic/temples/shar_tunnel2";

void create() {
        ::create();
        set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A narrow "+
           "opening leads to the mountainside east, while "+
           "the tunnel itself seems to mover further beneath "+
           "the mountain to the northwest.\n");
        set_exits(([
           "northwest" : "/d/magic/temples/shar_tunnel4",
           "out" : "/d/tharis/newtharis/mountain/spath4"
        ]));
}