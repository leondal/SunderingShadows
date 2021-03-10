#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,2",
        "south"     :DES+"desert_1,1",
        "west"      :DES+"desert_0,0"
             ]));
}