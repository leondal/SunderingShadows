#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room45",
        "east"      :BO+"room49",
        "south"     :BO+"room",
        "west"      :BO+"room2"
             ]));

}
