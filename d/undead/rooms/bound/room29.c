#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room38",
        "east"      :BO+"room27",
        "west"      :BO+"room39"
             ]));

}
