#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room20",
        "south"     :TOWN+"room22"
             ]));

}
