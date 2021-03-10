#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,3",
        "east"      :DES+"desert_5,4",
        "south"     :DES+"desert_6,3",
        "west"      :DES+"desert_5,2"
             ]));
}