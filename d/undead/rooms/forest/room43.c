#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room31",
        "west"      :PATH+"room42",
        "southwest" :PATH+"room53"
             ]));

}
