#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room45",
        "east"      :PATH+"room57",
        "west"      :PATH+"room55"
             ]));

}
