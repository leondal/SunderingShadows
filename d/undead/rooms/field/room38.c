#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "hill"      :BO+"room37",
        "meadow"    :BO+"room4",
        "west"      :BF+"room33"
             ]));

}

