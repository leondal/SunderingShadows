#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You can see the ruins "+
    "of the western half of the second floor below you.%^RESET%^");

    set_exits((["east" : RROOMS+"12", "north" : RROOMS+"16", "northeast" : RROOMS+"17",
    "south" : RROOMS+"6", "southeast" : RROOMS+"7" ]));

}
