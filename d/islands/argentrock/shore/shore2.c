#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( (["northeast":SHO+"shore1",
                "southwest":SHO+"shore3"]) );
}

