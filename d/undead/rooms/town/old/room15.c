#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"room16",
        "west"      :TOWN+"room13",
        "south"     :TOWN+"inn"
             ]));

}
