#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"room10",
        "south"     :BO+"room12"
             ]));

}
