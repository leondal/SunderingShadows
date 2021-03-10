#include <std.h>
#include "../defs.h"
inherit INH + "spiderarches";

void create()
{
    ::create();
    set_long("" + ::query_long() + "\n");
    set_exits(([
                   "south" : UPPER "tunnel29",
                   "southwest" : UPPER "tunnel31",
                   "west" : UPPER "tunnel34",
               ]));
}

// Removing "northwest":UPPER"tunnel38" as an exit due to Selucia collapsing the roof on it in the Ashra plot.
