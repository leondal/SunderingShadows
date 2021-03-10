#include "../undead.h"

inherit ROOM;

void create()
{
    ::create();

    set_name("Approaching the mountain peak");
    set_terrain(NEW_MOUNTS);
    set_travel(GAME_TRACK);
    set_property("indoors", 0);
    set_property("light", 2);
    set_climate("mountain");

    set_short("%^MAGENTA%^You are in the mountains");

    set_long("%^MAGENTA%^You are traveling a small path in the mountains.%^RESET%^\n"
        "%^CYAN%^All around you the treacherous peaks of the Thoradin Range rise up "
        "like daggers through the clouds. Right now you are traveling between "
        "the peaks in no particular direction, trying your best to keep your "
        "footing. You are now hiking up one of the largest mountains in the "
        "entire Thoradin Range. Few people ever bother to come up here, come "
        "to think of it, you have heard no tales of what may lay at the top "
      "of this mountain, and how you can %^RESET%^%^CYAN%^challenge %^RESET%^it.");

    set_exits(([
        "northeast":MTS+"room60",
        "southwest":MTS+"room67"
             ]));

    set_smell("default","The fresh scent of nature is about you.");
    set_listen("default","You can hear a few birds chirping around you.");

}
