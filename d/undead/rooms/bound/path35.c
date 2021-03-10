#include "../../undead.h"

inherit INH+"bound_three.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path34",
        "west"      :BO+"path36"
             ]));

}
