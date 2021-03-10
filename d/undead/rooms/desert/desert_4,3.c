#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,3",
        "east"      :DES+"desert_4,4",
        "south"     :DES+"desert_5,3",
        "west"      :DES+"desert_4,2"
             ]));
}