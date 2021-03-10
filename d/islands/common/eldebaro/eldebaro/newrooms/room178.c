#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"179",
        //"south" : ELROOMSD+"162",
        "west" : ELROOMSD+"177",        
    ]));
    set_climb_exits((["climb": ({ELDUNES+"3_2", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
}
