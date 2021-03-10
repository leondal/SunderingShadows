#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room14",
        "west"      :PATH+"room22",
        "southwest" :PATH+"room33"
             ]));

}
