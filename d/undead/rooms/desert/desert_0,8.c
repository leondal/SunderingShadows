#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,9",
        "south"     :DES+"desert_1,8",
        "west"      :DES+"desert_0,7"
             ]));
}