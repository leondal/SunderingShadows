#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room12",
        "east"      :BO+"room14",
        "west"      :BO+"room22"
             ]));

}
