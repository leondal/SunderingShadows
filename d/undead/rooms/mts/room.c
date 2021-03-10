#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast"     :MTS+"room2",
        "southwest"     :MTS+"room3"
             ]));

}