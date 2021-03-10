#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room5",
        "east"      :BO+"room7",
        "south"     :BO+"room28",
        "west"      :BO+"room40"
             ]));

}
