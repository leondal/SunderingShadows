#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"guard6",
        "west"      :TOWN+"guard4",
        "up"        :TOWN+"guard15"
             ]));

}
