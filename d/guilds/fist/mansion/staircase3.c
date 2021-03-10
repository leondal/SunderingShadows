#include <std.h>

inherit "/d/guilds/fist/mansion/staircase1";

void create() {
    ::create();
    set_exits(([
       "down" : "/d/guilds/fist/mansion/staircase2",       
    ] ));
}
