#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 2;
    ::create();
    mydest = ELDUNES + which_rune+"_";
    set_long(TO->query_long() +"%^RESET%^%^ORANGE%^ You can descend to the vast "+
    "s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ from here.%^RESET%^");
    
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
    
    set_climb_exits((["descend": ({ELROOMSD+"102", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
}
