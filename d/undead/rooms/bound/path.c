#include "../../undead.h"

inherit INH+"bound_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"path34",
        "south"     :BO+"room40",
        "east"      :BO+"path2"
             ]));

}
