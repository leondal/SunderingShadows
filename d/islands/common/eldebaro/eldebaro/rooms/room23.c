#include <std.h>
#include "../eldebaro.h"

inherit EL_INH;

void create()
{
    object ob, where;
    ::create();

    set_long("Three squarish boulders are here, formed into a monumental doorway of sorts.\n"
        ""+::query_long()+"");

    set_exits(([
        "north" : ROOMS"room22",
        "south" : "/d/shadow/virtual/sea/eldebaro.dock",
        "west" : ROOMS"room20",
        "east" : ROOMS"room26",
    ]));

    set_items(([
        ({"boulders","monument","doorway"}) : "Three boulders: two sit upright like columns, the third "
                                              "lays across the tops of the first two, forming a doorway "
                                              "of sorts, oriented east-west. They appear to have been here "
                                              "for a very long time."
    ]));

    ob = new("/d/islands/common/mon/uwarrior_sp");
    where = find_object_or_load(ROOMS"room"+(random(30)+5));
    if(objectp(where)) { ob->move(where); }
    else { ob->remove(); }
}
