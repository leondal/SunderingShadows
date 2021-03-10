#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("At the edge of a cliff");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^MAGENTA%^You stand at the edge of a cliff.%^RESET%^");
    
    set_long("%^MAGENTA%^You stand at the edge of a cliff overlooking the ocean.\n%^RESET%^"
        "%^BOLD%^%^BLUE%^You are now several hundred feet above the ocean looking "
        "down upon the crashing waves. There appears to be a small inlet here "
        "that may in the past have been used as a harbor. But it certainly "
        "would have been difficult landing.");
 
    set_exits(([
        "north"     :BO+"room23",
        "east"      :BO+"room21",
        "west"      :BO+"room24"
             ]));
    set_smell("default","The salty smell of the sea invades your nostrils.");
    set_listen("default","You can hear sea birds squawking in the air above you.");

}