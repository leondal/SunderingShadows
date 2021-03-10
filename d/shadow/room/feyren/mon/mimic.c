#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/mons/mimic_chest";

void create() 
{
    ::create();
    setMyMimicLevel(10, 12);
    switch(random(5))
    {
        case 0..2:
            set_my_treasure((["gold" : 400 + random(601)]));
            break;
        case 3:
            set_my_treasure((["gold" : 200 + random(201), 
            FFOB+"lightstone" : 1]));
            break;
        case 4:
            set_my_treasure((["gold" : 50 + random(101),
            FFOB+"patchwork_cloak" : 1]));
            break;
    }
}


