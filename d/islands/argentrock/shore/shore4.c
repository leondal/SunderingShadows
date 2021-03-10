#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( (["south":SHO+"shore5",
                "north":SHO+"shore3"]) );


}
