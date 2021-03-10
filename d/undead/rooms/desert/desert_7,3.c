#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,3",
        "east"      :DES+"desert_7,4",
        "south"     :DES+"desert_8,3",
        "west"      :DES+"desert_7,2"
             ]));
}