#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"guard8",
        "west"      :TOWN+"guard6",
        "up"        :TOWN+"guard17"
             ]));

}
