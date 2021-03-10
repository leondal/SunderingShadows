#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();
    
    set_exits(([
        "north"     :BO+"sroom23",
        "south"     :BO+"sroom30",
        "west"      :BO+"sroom25"
             ]));


    new(MON+"knight_of_ximes")->move(TO);
}
