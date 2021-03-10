#include <std.h>
#include "keep.h"

inherit VAULT;

void create() 
{
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_name("tower of hawk");
    set_short("%^YELLOW%^Inside the Tower of Hawk%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This large room is roughly ninety feet square with a large %^RED%^alcove%^RESET%^"+
    " set in the middle of each %^BLUE%^wall%^RESET%^.  The %^BOLD%^%^WHITE%^floor%^RESET%^ "+
    "is of highly polished %^BOLD%^%^BLACK%^marble%^RESET%^ and the twenty feet high "+
    "ceiling is of similar material.  During the day %^YELLOW%^light%^RESET%^ "+
    "enters the room through the %^BLUE%^windows%^RESET%^ in the %^RED%^alcoves%^RESET%^.");

    set_smell("default","An odor of decay mingles with a heavy scent of ale.");
    set_listen("default","An occassional shout can be heard from within the tower.");

    set_items(([
        ({"alcove","alcoves"}) : "%^RED%^These alcoves are set into each of the walls and lined "+
        "with windows.%^RESET%^",
        ({"wall","walls"}) : "%^BOLD%^%^WHITE%^The walls of this tower are made of a "+
        "%^BOLD%^%^BLACK%^marble%^BOLD%^%^WHITE%^ that has been kept polished.%^RESET%^",
        ({"floor","marble floor","polished floor","polished marble floor"}) : "%^BOLD%^%^BLACK%^"+
        "The floor of this tower is made from a marble that has been kept polished.%^RESET%^",
        ({"ceiling","marble ceiling","polished ceiling","polished marble ceiling"}) : "%^BOLD%^"+
        "%^BLACK%^The ceiling of this tower is approximately twenty feet high and is made from "+
        "a marble that has been kept polished.%^RESET%^",
        ({"window","windows"}) : "%^CYAN%^The windows within these alcoves are made of a thin "+
        "glass.%^RESET%^",
        ({"stairs","staircase","stone stairs","stone staircase"}) : "%^BOLD%^%^WHITE%^These stairs "+
        "dominate the chamber.%^RESET%^",
        "marble" : "%^BOLD%^%^WHITE%^The walls, floor, and ceiling are all constructed of a "+
        "marble that has been kept polished.%^RESET%^",
    ] ));
}

void reset() {
    int x;
    ::reset();
    if(!present("keep archer") && random(10) >= 8 && base_name(TO) != HTOWER && 
    base_name(TO) != KEEPR+"tower4") 
    {
        for(x = 0;x < random(2) + 1;x++) 
        {
            new(KEEPM+"archer")->move(TO);
        }
    }
}
