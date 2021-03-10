#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :TOWN+"cast12",
        "south"     :TOWN+"cast8"
             ]));

}
