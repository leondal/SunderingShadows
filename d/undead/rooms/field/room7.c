#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room6",
        "east"      :BF+"room17",
        "south"     :BF+"room9"
             ]));

}