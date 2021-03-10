#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room39"
             ]));

}
