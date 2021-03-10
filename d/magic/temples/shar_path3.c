#include <std.h>
inherit "/d/magic/temples/shar_path2";

void create() {
        ::create();
        set_exits(([
           "northeast" : "/d/magic/temples/shar_path2",
           "west" : "/d/magic/temples/shar_path4"
        ]));
}
