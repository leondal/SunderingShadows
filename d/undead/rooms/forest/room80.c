#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room75",
        "beach"     :BO+"room18",
        "northeast" :PATH+"room76",
        "northwest" :PATH+"room74"
             ]));

}
