#include "/d/islands/dallyh/fways.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_short("%^RESET%^%^ORANGE%^An inviting shelter%^RESET%^");
    set_name("an inviting shelter");
    set_long("%^RESET%^%^GREEN%^From here you can tell that this large shelter "+
    "has not been built up into the trees, but rather it is part of them. "+
    "It looks %^BOLD%^%^BLACK%^ancient%^RESET%^%^GREEN%^ and %^BOLD%^%^WHITE%^sturdy"+
    "%^RESET%^%^GREEN%^. You are not sure if it was created or simply developed, it is "+
    "impossible to tell. This particular shelter seems to have been set up for one purpose... "+
    "anticipation of your arrival. It is almost completely smooth and bare, as if whatever "+
    "created or developed it willed it to be so. It manages to exude peace while at the same "+
    "time alluding to some unknown power that provides a slight feeling of unease.%^RESET%^");
    set_property("indoors",0);
    set_light(2);
    set_listen("default","An eerie stillness hangs in the air here.");
    set_smell("default","A scent vaguely reminiscent of springtime wafts from the orb.");
    set_items( ([ 
        ({"shelter", "shelters", "inviting shelter", "trees"}) : "%^RESET%^%^GREEN%^This large "+
        "shelter has not been built up into the trees. It is actually a part of the trees. "+
        "It is almost as if it inside of them and the trees actually seem to be continually "+
        "growing around it, providing it with an enormous amount of protection. It seems very "+
        "sturdy and quite ancient.%^RESET%^",
    ]));
    set_exits(([
        "north":FRPATH "road3",
    ]));
}


void reset() {
    ::reset();
    if(!present("dallyhorboflightsaide"))
    {
        new( FOPATH "orb_of_light")->move(this_object());
    }
}
