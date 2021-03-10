#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,3",
        "east"      :DES+"desert_6,4",
        "south"     :DES+"desert_7,3",
        "west"      :DES+"desert_6,2"
             ]));
}