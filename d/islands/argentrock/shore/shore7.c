#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( (["south":SHO+"shore8",
                "north":SHO+"shore6"]) );


}
