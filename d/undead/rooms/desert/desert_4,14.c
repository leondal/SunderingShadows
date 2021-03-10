#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,14",
        "south"     :DES+"desert_5,14",
        "west"      :DES+"desert_4,13"
             ]));
}