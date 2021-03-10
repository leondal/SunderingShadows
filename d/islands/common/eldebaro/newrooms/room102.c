#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"116",
        "east" : ELROOMSD+"103",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"101",        
    ]));
    set_climb_exits((["climb": ({ELDUNES+"2_5", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
    
}
