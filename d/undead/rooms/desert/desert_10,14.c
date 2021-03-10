#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,14",
        "south"     :DES+"desert_11,14",
        "west"      :DES+"desert_10,13"
             ]));
}