#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room57",
        "south"     :PATH+"room73",
        "southwest" :PATH+"room72"
             ]));

}
