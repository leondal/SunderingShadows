#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,4",
        "east"      :DES+"desert_5,5",
        "south"     :DES+"desert_6,4",
        "west"      :DES+"desert_5,3"
             ]));
}