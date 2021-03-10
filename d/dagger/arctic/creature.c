#include <std.h>
#include "/d/common/common.h"
#include "arctic.h"

inherit WEAPONLESS;

object owner;


void create(){::create();}

int is_fodder(object obj)
{ 
    if(obj->id("arcticmon")) return 0; 
    if(obj->is_player()) return 0;
    if(obj->id("summoned monster")) return 1;
    else return 0;
}

void nogo(string str)
{
    if(!str) return;

    if(str == "NOGO_G")
    {
        set_nogo(({ CAVE"cave53" }));
    }

    if(str == "NOGO1")
    {
        set_nogo(({ LAKE"road1",
                    UW"uw1",
                    UW"uw2",
                    LAIR"giants1"
                }));
    }

    if(str == "NOGO2")
    {
        set_nogo(({ ROOMS"lake.c",
                    CAVE"cave1",
                    LAKE"waterfall",
                    LAKE"road8",
                    LAKE"lake1",
                    LAKE"lake2",
                    LAKE"road7",
                    LAKE"lake3",
                    LAKE"lake4",
                    LAKE"lake5",
                    LAKE"lake6",
                    LAKE"lake7",
                    LAKE"lake8",
                    LAKE"lake9",
                    LAKE"lake10",
                    LAKE"lake11",
                    LAKE"lake12",
                    LAKE"lake13",
                    LAKE"lake14",
                    LAKE"lake15",
                    LAKE"lake16",
                    UW"bottom"
                 }));
            }
    return;
}
