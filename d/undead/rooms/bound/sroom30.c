#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom26",
        "south"     :BO+"room56",
        "west"      :BO+"sroom29"
             ]));

}
