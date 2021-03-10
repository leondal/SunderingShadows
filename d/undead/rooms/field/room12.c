#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room10",
        "east"      :BF+"room25",
        "southwest" :BF+"room13",
        "west"      :BF+"room11"
             ]));

}
