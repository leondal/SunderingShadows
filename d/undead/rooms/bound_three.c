#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A trail through Peth Forest");
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^BOLD%^You are on a trail.%^RESET%^");
    
    set_long("%^BOLD%^You are on a small trail which cuts through the woods.\n%^RESET%^"
        "To the east you see the the %^GREEN%^Peth Forest%^RESET%^, its jagged trees rising "
        "far into the sky, nearly blocking out the sun. To the southeast you can "
        "see the fine grass of a meadow, billowing in the wind. In the distance, "
        "to the north, the peaks of the Thoradin Mountains rise up through the haze "
        "and into the clouds. To your south you can see fire and smoke rising "
        "from the battlefield.%^RESET%^");

    set_exits(([
        "east"      :BO+"path",
        "west"      :BO+"path35"
             ]));

    set_smell("default","The smell of the wild pervades your senses.");
    set_listen("default","You can hear the ravens cawing and the river rushing.");
}