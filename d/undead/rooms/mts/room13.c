#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
 ::create();

    set_exits(([
        "north"     :MTS+"room9",
        "southeast" :MTS+"room12",
        "west"      :MTS+"room14"
             ]));

}
