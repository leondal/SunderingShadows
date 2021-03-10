#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,3",
        "east"      :DES+"desert_3,4",
        "south"     :DES+"desert_4,3",
        "west"      :DES+"desert_3,2"
             ]));
}