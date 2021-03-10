#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room10",
        "east"      :BO+"room12",
        "south"     :BO+"room22",
        "west"      :BO+"room25"
             ]));

}
