#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,7",
        "south"     :DES+"desert_1,6",
        "west"      :DES+"desert_0,5",
        "up"        :MTS+"room105"
             ]));
}