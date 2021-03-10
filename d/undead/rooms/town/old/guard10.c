#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "southwest" :TOWN+"guard11",
        "up"        :TOWN+"guard20"
             ]));

}
