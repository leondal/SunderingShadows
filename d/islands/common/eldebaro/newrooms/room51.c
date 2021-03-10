#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMSD+"62",
        "east" : ELROOMSD+"52",
        "south" : ELROOMSD+"36",
        "west" : ELROOMSD+"50",        
    ]));
    
    set_climb_exits((["climb": ({ELDUNES+"1_5", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
}
