#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "swamp"     :BO+"sroom24",
        "north"     :PATH+"room61",
        "southwest" :PATH+"room76"
             ]));

}
