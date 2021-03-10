#include "../../undead.h"

inherit INH+"tomb_four.c";

void create() 
{
    ::create();

    set_long("%^BOLD%^%^RED%^You are in a small circular stairwell.%^RESET%^\n"
        "%^BLUE%^As you gaze up the stairwell your vision is obscured by "
        "an incredibly thick fog.  The fog seems to begin a foot above the "
        "doorway and you can see no definate end to it.  To your south "
        "you see the hallways you've just been walking through.");
 
    set_exits(([
        "up"        :HALL+"stair2",
        "south"     :HALL+"hall4"
             ]));

}
