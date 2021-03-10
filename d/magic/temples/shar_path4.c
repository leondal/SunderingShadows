#include <std.h>
inherit "/d/magic/temples/shar_path2";

void create() {
        ::create();
        set_exits(([
           "east" : "/d/magic/temples/shar_path3",
           "northwest" : "/d/magic/temples/shar_path5"
        ]));
}
