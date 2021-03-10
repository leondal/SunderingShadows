#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room43",
        "south"     :BO+"room46",
        "west"      :BO+"room41"
             ]));

}
