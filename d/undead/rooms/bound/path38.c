#include "../../undead.h"

inherit INH+"bound_three.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path37",
        "down"      :TOWN+"ditch6",
        "west"      :BO+"path39"
             ]));

}
