#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room11",
        "east"      :BO+"room13",
        "south"     :BO+"room21",
        "west"      :BO+"room23"
             ]));

}
