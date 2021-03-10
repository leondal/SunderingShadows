#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "hill"      :BO+"room10",
        "northeast" :PATH+"room55",
        "southeast" :PATH+"room71"
             ]));

}
