#include <std.h>
#include "../inherits/area_stuff.h"
inherit RT;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ You are on the edge of the "+
    "roof and could %^BOLD%^%^MAGENTA%^jump%^BOLD%^%^WHITE%^ down "+
    "into the courtyard far below if you were so inclined. You can see the ruins "+
    "of the western half of the second floor below you.%^RESET%^");

    set_exits((["east" : RROOMS+"2", "north" : RROOMS+"6", "northeast" : RROOMS+"7" ]));

    set_property("jump_destination", "south");		

}
