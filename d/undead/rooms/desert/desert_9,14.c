#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,14",
        "south"     :DES+"desert_10,14",
        "west"      :DES+"desert_9,13"
             ]));
}