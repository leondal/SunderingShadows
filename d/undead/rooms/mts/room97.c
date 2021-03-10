#include "../../undead.h"

inherit INH+"mts_eight.c";

void create()
{
    ::create();

    set_exits(([
        "south":MTS+"room96",
   ]));
}

void init(){
   ::init();
}
