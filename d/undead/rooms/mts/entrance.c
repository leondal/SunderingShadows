#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("Medusa's Lair Entrance");
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);


    set_short("%^BOLD%^You are in the mountains.%^RESET%^");
    
    set_long("%^BOLD%^The mouth of a giant snake is carved into the mountains.%^RESET%^\n"
        "It is obvious that this monstrosity was carved into the mountain wall "
        "many decades ago. Though it is still quite intimidating to say the least.  "
        "Between the two giant teeth is a flat stone surface, that looks like "
        "it might be slightly ajar. Perhaps with a little effort you might be "
        "able to pry it open. But what could possibly rest within this ancient "
        "tomb.");
 
    set_exits(([
        "north"      :MTS+"lair",
        "southwest" :MTS+"room2"
             ]));

    set_smell("default","The fresh air of the mountains fills your lungs.");
    set_listen("default","No sound exits near this tomb.");

    set_door("tomb door",MTS"lair","north","open_tomb_door");
    set_open("tomb door",0);
    set_string("tomb door","open", "Dust billows up as you crack the tomb doors open!");

}
