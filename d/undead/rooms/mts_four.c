#include "../undead.h"

inherit ROOM; // looks like the begging of another sub area that was never finished

void create() 
{
    ::create();
    
    set_name("A high mountain grove");
    set_terrain(NEW_MOUNTS);
    set_travel(GAME_TRACK);
    set_property("indoors", 0);
    set_property("light", 2);
    set_climate("mountain");

    set_short("%^MAGENTA%^You are in the mountains");

    set_long("%^MAGENTA%^You are traveling a small path in the mountains.%^RESET%^\n"
        "All around you the treacherous peaks of the Thoradin Range rise up "
        "like daggers through the clouds. Right now you are traveling between "
        "the peaks in no particular direction, trying your best to keep your "
        "footing. To the south you see a small patch of forest tucked into "
        "the mountain's side. There looks to be smoke rising up from the center "
        "of the grove.");
 
    set_exits(([
        "northeast" :MTS+"room12"
             ]));

    set_smell("default","The fresh scent of nature is about you.");
    set_listen("default","You can hear a few birds chirping around you.");

}