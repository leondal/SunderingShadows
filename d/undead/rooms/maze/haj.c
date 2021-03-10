#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_long( ::query_long() + "  You notice a slight movement in the "
        "shadows, and start to move just in time to avoid the crushing "
        "blow of the Hand of Justice!");

    set_exits(([
        "west"      :MAZ+"room38"
             ]));

}


void reset() 
{
    ::reset();
    if(!present("hand")) { new(MON+"hand_of_justice")->move(TO); }
}
