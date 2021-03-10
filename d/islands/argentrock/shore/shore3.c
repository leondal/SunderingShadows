#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( (["northeast":SHO+"shore2",
                "south":SHO+"shore4"]) );


}
