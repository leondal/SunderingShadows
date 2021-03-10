#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You can see the ruins "+
    "of the western half of the second floor below you.%^RESET%^");

    set_exits((["east" : RROOMS+"22", "north" : RROOMS+"26", "northeast" : RROOMS+"27",
    "south" : RROOMS+"16", "southeast" : RROOMS+"17" ]));

}
