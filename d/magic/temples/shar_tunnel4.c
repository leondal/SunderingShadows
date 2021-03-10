#include <std.h>
inherit "/d/magic/temples/shar_tunnel2";

void create() {
        ::create();
        set_exits(([
           "west" : "/d/magic/temples/shar_tunnel3",
           "southeast" : "/d/magic/temples/shar_tunnel5"
        ]));
}