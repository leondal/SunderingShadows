#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BF+"room26",
        "meadow"    :BO+"room36",
        "hill"      :BO+"room37",
        "south"     :BF+"room33"
             ]));

}

