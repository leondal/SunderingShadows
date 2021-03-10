#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,14",
        "south"     :DES+"desert_9,14",
        "west"      :DES+"desert_8,13"
             ]));
}