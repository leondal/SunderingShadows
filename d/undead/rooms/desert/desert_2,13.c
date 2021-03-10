#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,13",
        "east"      :DES+"desert_2,14",
        "south"     :DES+"desert_3,13",
        "west"      :DES+"desert_2,12"
             ]));
}