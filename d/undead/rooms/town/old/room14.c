#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"room12",
        "west"      :TOWN+"room17"
             ]));

}
