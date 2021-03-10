#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You can see the ruins "+
    "of the western half of the second floor below you.%^RESET%^");

    set_exits((["east" : RROOMS+"7", "north" : RROOMS+"11", "northeast" : RROOMS+"12",
    "south" : RROOMS+"1", "southeast" : RROOMS+"2" ]));

}
