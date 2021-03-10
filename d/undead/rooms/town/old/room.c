#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room2",
        "south"     :"/d/shadow/virtual/sea/undead.dock",
             ]));

}
