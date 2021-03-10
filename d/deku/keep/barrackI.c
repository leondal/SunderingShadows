#include <std.h>
#include "keep.h"
inherit ROOM;
void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_name("barracks of keep blacktongue");
    set_short("%^YELLOW%^Barracks of Keep Blacktongue%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This is the inside of the Keep Blacktongue barracks.  The room is about "+
    "thirty feet across and about fifteen feet high.  There are %^BOLD%^%^WHITE%^stairs%^RESET%^ "+
    "going up along the northern wall.  The room is filled with old %^RED%^beds%^RESET%^ of "+
    "all sizes.  Along the side of each bed is a small %^YELLOW%^locker%^RESET%^.\n");
 
    set_listen("default","An occassional shout echoes through the keep.");
    set_smell("default","An odor of death hangs heavily in the air.");
    set_exits(([
        "south" : KEEPR + "keepE1",
        "up" : KEEPR + "barrack_u1"
    ] ));
    set_items(([
        ({"beds","bed"}) : "%^RED%^These beds are all unmade and filthy, hygiene is not a concern "+
        "of the creatures that rest in them.%^RESET%^",
        "locker" : "%^YELLOW%^The small locker holds clothing and various items for whatever "+
        "creatures dwell here.%^RESET%^",
        "stairs" : "%^BOLD%^%^WHITE%^These stones stairs travel upward along the northern wall "+
        "to the top of this tower.%^RESET%^"
    ] ));
}

void reset() 
{
    int x;
    ::reset();
    if(base_name(TO) != BB) 
    {
        if(!present("kguard") && random(8) > 5) 
        {
            for(x = 0; x < random(3) + 1;x++) 
            {
                new(KEEPM + "keep_guard")->move(TO);
            }
        }
    }
}
