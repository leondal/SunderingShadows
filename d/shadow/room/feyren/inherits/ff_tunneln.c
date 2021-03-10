#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"
inherit ROOM;
int searched;

void create() 
{
    ::create();
    set_property("no teleport", 1);
    set_property("light",0);
    set_property("indoors",1);
    set_name("A crack through the earth");
    set_short("%^BOLD%^%^MAGENTA%^A crack through the earth%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^MAGENTA%^You are traversing through a "+
    "crack in the very %^RESET%^%^RED%^earth%^BOLD%^%^MAGENTA%^. "+
    "The area around you is so incredible narrow that movement is "+
    "very difficult. Massive %^BOLD%^%^BLACK%^roots%^BOLD%^%^MAGENTA%^"+
    " jut out all over in various angles, serving to make this "+
    "journey even more uncomfortable. You can feel the earth "+
    "giving away beneath your feet with each step. Overhead "+
    "the crack narrows to the point of being impassable and "+
    "at it feels as if at any movement the earth around "+
    "you might cave in, trapping you here.%^RESET%^");

    set_smell("default","The odor of fresh earth overrides all other smells here.");
    set_listen("default","The only sound is your own heartbeat.");

    set_items(([({"earth", "crack"}) : "%^RED%^The "+
    "earth is all around you here, you are almost "+
    "entombed in it.%^RESET%^",
    ({"root", "roots"}) : "%^BOLD%^%^BLACK%^"+
    "These massive roots invade this narrow crack at "+
    "varying angles. They snake about wildly and "+
    "make movement here even more difficult.%^RESET%^"
    ]) ); 

    searched = random(4);

}

void CheckCollapse()
{
    string cexit, *exits;
    int x, y;
    if(!objectp(TO)) return;
    if(!sizeof(TO->query_exits())) return;
    if(sizeof(TO->query_buried_exits())) return;
    if(random(5)) return;
    y = random(10);
    x = sizeof(TO->query_exits());
    exits = TO->query_exits();
    if(x == 1) y = 1;
    switch(random(10))
    {
        case 0..8:
            cexit = exits[random(x)];
            tell_room(TO, "%^BOLD%^%^BLACK%^A violent shuddering "+
            "shakes the very earth around you and you watch "+
            "in horror as the opening "+
            "to the %^BOLD%^%^RED%^"+
            cexit+"%^BOLD%^%^BLACK%^ collapses!%^RESET%^");
            TO->collapse_exit(cexit, 100);
            break;
        case 9:
            tell_room(TO, "%^BOLD%^%^BLACK%^A violent shuddering "+
            "shakes the very earth around you and you watch "+
            "in horror as %^BOLD%^%^RED%^"+
            "ALL%^BOLD%^%^BLACK%^ the openings leading "+
            "out of here collapse!%^RESET%^");
            TO->collapse_all_exits(100);
            break;
    }
    return;
}

/*void init()
{
	::init();
	CheckCollapse();
}*/
