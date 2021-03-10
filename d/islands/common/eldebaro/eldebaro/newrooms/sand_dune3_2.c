#include <std.h>
#include "../area_stuff.h"

inherit ELDUNE;

void create()
{
    string mydest;
    which_rune = 3;
    ::create();
    mydest = ELDUNES + which_rune+"_";
    set_long(TO->query_long() +"%^RESET%^%^ORANGE%^ You can descend to the vast "+
    "s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ from here.%^RESET%^");
    set_exits(([
        //"north" : ELDUNES + "1_2",
        //"northeast" : ELDUNES + "1_3",
        //"northwest" : ELDUNES + "1_1",
        "east" : mydest + "3",
        "west" : mydest + "1",
        "southeast" : mydest + "6",
        "south" : mydest + "5",
        "southwest" : mydest + "4"
    ]));
    set_climb_exits((["descend": ({ELROOMSD+"178", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!^RESET%^");
}
