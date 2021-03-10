#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/mons/mimic_chest";

void create() 
{
    ::create();
    setMyMimicLevel(18, 20);
    switch(random(8))
    {
        case 0..5:
            set_my_treasure((["gold" : 2400 + random(601)]));
            break;
        case 6..7:
            set_my_treasure((["gold" : 1300 + random(201), 
            CROB+"crater_weapon" : 1]));
            break;
    }
}


