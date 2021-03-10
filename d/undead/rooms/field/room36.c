#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room35",
        "cliff"     :BO+"room39",
        "west"      :BF+"room30"
             ]));

}
