#include "../../undead.h"

inherit INH+"town_two.c";

void create() 
{
    ::create();

    set_exits(([
        "up"        :TOWN+"guard22",
        "east"      :TOWN+"guard11",
        "west"      :TOWN+"room9"
             ]));

}
