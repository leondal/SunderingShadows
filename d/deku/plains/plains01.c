#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"A trail leads southwest here and "+
    "into the depths of the shadowlord forest.");
    set_exits(([
       "southwest" : "/d/deku/plains/fplains06",
       "west" : "/d/deku/plains/plains02"
    ] ));
}
