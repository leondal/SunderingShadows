#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room15",
        "east"      :PATH+"room25",
        "southeast" :PATH+"room36"
             ]));

}
