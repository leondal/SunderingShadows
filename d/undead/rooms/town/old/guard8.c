#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :TOWN+"guard7",
        "up"        :TOWN+"guard18"
             ]));

}
