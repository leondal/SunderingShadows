#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room33",
        "east"      :BF+"room39",
        "south"     :BF+"room35"
             ]));

    new(MON+"lord_soth")->move(TO);
}
