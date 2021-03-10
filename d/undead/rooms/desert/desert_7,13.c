#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,13",
        "east"      :DES+"desert_7,14",
        "south"     :DES+"desert_8,13",
        "west"      :DES+"desert_7,12"
             ]));
}