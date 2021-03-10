#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You can see the ruins "+
    "of the western half of the second floor below you.%^RESET%^");

    set_exits((["east" : RROOMS+"17", "north" : RROOMS+"21", "northeast" : RROOMS+"22",
    "south" : RROOMS+"11", "southeast" : RROOMS+"12" ]));

}
