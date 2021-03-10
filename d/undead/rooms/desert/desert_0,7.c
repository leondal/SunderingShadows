#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,8",
        "south"     :DES+"desert_1,7",
        "west"      :DES+"desert_0,6"
             ]));
}