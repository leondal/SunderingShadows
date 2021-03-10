#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("On a beach");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);
    
    set_short("%^YELLOW%^You are on a beach.%^RESET%^");
    
    set_long("%^BOLD%^%^YELLOW%^You are walking along a sandy beach.\n%^RESET%^"
        "To your north is the dreaded Peth Forest, where no being of good is "
        "welcome. East of your position you can see a large river cutting "
        "through the land. You have heard of this river in legend, the natives "
        "call it the %^BLUE%^River of Sorrows%^RESET%^, which does not sound "
        "hopefull to you.  To your west you can see a hilly meadow, filled with "
        "tall grass.  From where you stand you have an incredible view of the "
        "ocean, it's truly incredible.");

    set_exits(([
        "north"     :BO+"room11",
        "east"      :BO+"room13",
        "south"     :BO+"room21",
        "west"      :BO+"room23"
             ]));

    set_smell("default","The salty smell of the sea invades your nostrils.");
    set_listen("default","You can hear sea birds squawking in the air above you.");

}