#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,13",
        "south"     :DES+"desert_1,12",
        "west"      :DES+"desert_0,11"
             ]));
}