#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,14",
        "south"     :DES+"desert_2,14",
        "west"      :DES+"desert_1,13"
             ]));
}