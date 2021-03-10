#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    which_rune = 1;
    ::create();
    set_long(TO->query_long() +"%^RESET%^%^ORANGE%^ You can descend to the vast "+
    "s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ from here.%^RESET%^");
    
    set_exits(([
        "north" : ELDUNES + "1_2",
        "northeast" : ELDUNES + "1_3",
        "northwest" : ELDUNES + "1_1",
        "east" : ELDUNES + "1_6",
        "west" : ELDUNES + "1_4",
        "southeast" : ELDUNES + "1_9",
        "south" : ELDUNES + "1_8",
        "southwest" : ELDUNES + "1_7"
    ]));
    
    set_climb_exits((["descend": ({ELROOMSD+"51", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
}
