#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "path"      :BO+"path39",
        "south"     :BF+"room2"
             ]));

}
