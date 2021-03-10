#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( (["southeast":SHO+"shore6",
                "north":SHO+"shore4"]) );


}
