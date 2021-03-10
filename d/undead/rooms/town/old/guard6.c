#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"guard7",
        "west"      :TOWN+"guard5",
        "up"        :TOWN+"guard16"
             ]));

}
