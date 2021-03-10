#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :PATH+"room23",
        "southwest" :PATH+"room44"
             ]));

}
