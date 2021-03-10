#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :BO+"path27",
        "south"     :BO+"path25"
             ]));

}
