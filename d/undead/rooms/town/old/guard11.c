#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :TOWN+"guard10",
        "west"      :TOWN+"guard12",
        "up"        :TOWN+"guard21"
             ]));

}
