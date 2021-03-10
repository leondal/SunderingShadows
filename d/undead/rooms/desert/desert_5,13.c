#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,13",
        "east"      :DES+"desert_5,14",
        "south"     :DES+"desert_6,13",
        "west"      :DES+"desert_5,12"
             ]));
}