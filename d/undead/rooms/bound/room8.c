#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room7",
        "east"      :BO+"room9",
        "south"     :BO+"room26",
        "west"      :BO+"room28"
             ]));

}
