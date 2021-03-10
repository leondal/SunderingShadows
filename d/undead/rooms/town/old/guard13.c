#include "../../undead.h"

inherit INH+"town_three.c";

void create() 
{
    ::create();

    set_exits(([
        "down"      :TOWN+"guard3"
             ]));

}
