#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room23",
        "east"      :BO+"room21",
        "west"      :BO+"room24"
             ]));

}
