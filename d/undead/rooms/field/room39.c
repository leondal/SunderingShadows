#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "meadow"    :BO+"room5",
        "west"      :BF+"room34"
             ]));

}