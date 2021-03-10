#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room28",
        "south"     :BF+"room30",
        "west"      :BF+"room21"
             ]));

}