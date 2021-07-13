#include <std.h>
inherit "/d/magic/temples/shar_path2";

void create() {
        ::create();
        set_exits(([
           "southeast" : "/d/magic/temples/shar_path4",
           "out" : "/d/magic/temples/lord_shadow/lord_shadowentry",
           //"southwest" : "/d/magic/temples/shar_courtyard"
           "southwest" : "/d/magic/temples/ashra/courtyard",
        ]));
}
