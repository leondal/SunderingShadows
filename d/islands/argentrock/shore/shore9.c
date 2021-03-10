#include <std.h>
#include "/d/islands/argentrock/argabbr.h"
inherit "/d/islands/argentrock/inherit/shore";

void create() {
    ::create();
   set_exits( ([
                "north":SHO+"shore8",
				"southeast":SHO+"shore10",]) );


}
