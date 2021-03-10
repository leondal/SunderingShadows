//  Made READABLE By FireDragon
#include <std.h>
#include "../../undead.h"

inherit HEALER;

void create() 
{
    ::create();

    set_name("Sabrina");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("training",1);

    set_short("Sabrina's Healing Parlor");

    set_long("%^BOLD%^You step into Sabrina's Healing Parlor.\n"
        "%^BOLD%^%^BLUE%^Herbs hang from the ceiling everywhere, and "
        "spell components clutter shelves around the room. A pleasant "
        "fire burns in the center of the room, and just to the side of "
        "it sits Sabrina herself, on a pad of cushions,");
    
    set_exits(([
        "west"      :TOWN"room22"
             ]));


    set_smell("default", "The strong odor of herbs and balms turns your stomach.");
    set_listen("default","You hear the twigs crackling in the fire.");
}

void reset()
{
    ::reset();
    if(!present("sabrina")) { new(MON"sabrina")->move(TO); }
    return;
}
