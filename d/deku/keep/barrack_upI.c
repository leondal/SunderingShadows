#include <std.h>
#include "keep.h"
inherit ROOM;
void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_name("captain quarters");
    set_short("%^YELLOW%^Captain Quarters%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This is the second floor of the barracks, where the captain of the guard "+
    "resides.  The room is about fifty feet across and fifteen feet high.  There is a "+
    "comfortable looking %^RED%^bed%^RESET%^ in the northwest corner and a small wooden "+
    "%^YELLOW%^table%^RESET%^ stands against the west wall with a padded leather %^RED%^chair"+
    "%^RESET%^ next to it.\n");

    set_listen("default","An occassional shout echoes through the keep.");
    set_smell("default","An odor of death hangs heavily in the air.");
    set_items(([
        "bed" : "%^RED%^This bed is unmade and very filthy.  Obviously the creature that sleeps "+
        "in it is not concerned with hygiene.%^RESET%^",
        ({"table","wood table","wooden table"}) : "%^YELLOW%^This table stands against the "+
        "west wall and is completely bare.  A thick layer of dust has settled on it.%^RESET%^",
        ({"chair","leather chair","padded chair","padded leather chair"}) : "%^RED%^This "+
        "chair is made from a dark leather and is in a state of filth.  It looks as if "+
        "it hasn't been used in sometime and it wreaks of something foul.%^RESET%^"
    ] ));
}

void reset() 
{
    int x;
    ::reset();
    if(base_name(TO) != UB) 
    {
        if(!present("kcaptain") && random(8) > 5) 
        {
            new(KEEPM + "keep_captain")->move(TO);
        }
        if(!present("kguard") && random(8) > 3) 
        {
            for(x = 0;x < random(3) + 1;x++) 
            {
                new(KEEPM + "keep_guard")->move(TO);
            }
        }
    }
}
