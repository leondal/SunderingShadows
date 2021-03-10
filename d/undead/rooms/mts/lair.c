#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("Medusa's Lair");
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("no teleport", 1);
    
    set_short("Mountain Temple");
    
    set_long("%^BLUE%^You are traveling through an ancient temple of some kind.%^RESET%^\n"
        "Snakes are depicted on all of the walls in various pictograms, and "
        "sculptures. The place gives you the shivers quite frankly, even the "
        "mist seems to move with a life of its own. And you hear a continuous "
        "hissing from all around you. You truly begin to wonder about the "
        "kind of people that would erect such an unholy temple up in these "
        "god forsaken mountains.");

    set_exits(([
        "north"     :MTS+"lair2",
        "south"     :MTS+"entrance"
             ]));

    set_door("tomb door",MTS"entrance","south","open_tomb_door");
    set_open("tomb door",0);
    set_string("tomb door","open", "Dust billows up as you crack the tomb doors open!");


}
