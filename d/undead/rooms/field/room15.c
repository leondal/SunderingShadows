#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room22",
        "south"     :BF+"room16",
        "west"      :BF+"room4"
             ]));

}