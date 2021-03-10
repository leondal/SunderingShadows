#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,13",
        "east"      :DES+"desert_3,14",
        "south"     :DES+"desert_4,13",
        "west"      :DES+"desert_3,12"
             ]));
}