#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"room12",
        "south"     :BO+"room14"
             ]));

}
