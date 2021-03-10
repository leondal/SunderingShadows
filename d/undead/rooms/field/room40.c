#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BF+"room35",
        "meadow"    :BO+"room6"
             ]));

}