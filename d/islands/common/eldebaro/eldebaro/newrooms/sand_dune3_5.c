#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 3;
    ::create();
    mydest = ELDUNES + which_rune+"_";
      
    set_exits(([
        "north" : mydest+"2",
        "northeast" : mydest+"3",
        "northwest" : mydest+"1",
        "east" : mydest+"6",
        "west" : mydest+"4",
        "southeast" : mydest+"9",
        "south" : mydest+"8",
        "southwest" : mydest+"7"
    ]));
    
}
