#include <std.h>
#include "../defs.h"
inherit INH + "spiderarches";

void create()
{
    ::create();
    set_long("" + ::query_long() + "\n");
    set_exits(([
                   "east" : UPPER "tunnel39",
                   "southeast" : UPPER "tunnel29",
                   "south" : UPPER "tunnel34",
                   "west" : UPPER "tunnel36", ]));
}

// Removing "northeast":UPPER"tunnel38" as an exit due to Selucia collapsing the roof on it in the Ashra plot.
