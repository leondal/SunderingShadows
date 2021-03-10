#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,13",
        "east"      :DES+"desert_6,14",
        "south"     :DES+"desert_7,13",
        "west"      :DES+"desert_6,12"
             ]));
}