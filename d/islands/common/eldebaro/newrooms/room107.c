#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"121",
        "east" : ELROOMSD+"108",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"106",        
    ]));
    set_climb_exits((["climb": ({ELDUNES+"4_5", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
}
