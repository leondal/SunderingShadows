#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room46",
        "west"      :BO+"room48"
             ]));

}
