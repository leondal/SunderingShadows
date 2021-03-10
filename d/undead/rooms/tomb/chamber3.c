#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_long("%^BLUE%^You are in a faintly lit Chamber\n"
        "%^BOLD%^%^BLACK%^You stand in a chamber shaped like a perfect "
        "cube.  It contains a large number of statues shaped from a black "
        "material the likes of which you have never seen before.  What light "
        "there is here comes from a small lantern on the ceiling, but all "
        "but the smallest portion of that light seems to be being absorbed "
        "by the metal statues.");
 
    set_exits(([
        "west":HALL+"hall8"
             ]));

}

void reset() 
{
    ::reset();
    if(!present("golem"))
    {
        new(MON+"golem")->move(TO);
        new(MON+"golem")->move(TO);
    }
}
