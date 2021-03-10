#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    ::create();

    set_long("The tops of crumbled walls just barely protrude from the sand.  A "
        "long stone column leans against one of the walls, covered in sand.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room30",
        "south" : ROOMS"room32",
        "west" : ROOMS"room25",
        "east" : ROOMS"room36",
    ]));

    set_items(([
        "column" : "A narrow marble column.  It is amazing that it survived this long.",
        "walls" : "They just barely rise from the desert sands.",
    ]));
}