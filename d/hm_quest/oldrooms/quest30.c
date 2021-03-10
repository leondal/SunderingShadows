#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("You hope you have come to the end of your journey.  A large temple-like "
        "building stands before you.  Shaped like a cone, built of gray stone "
        "and reaching a height of approximately 60 feet, it looms, dark, cold, "
        "yet wondrous.  You see someone standing before you, and you feel that "
        "he would try to bar your passage into the temple.");

    set_exits(([
        "temple" : "/d/hm_quest/rooms/quest31",
        "southwest" : "/d/hm_quest/rooms/quest29"
    ]));

    add_pre_exit_function("southwest","go_back");
    add_pre_exit_function("temple","GoThroughDoor");
}

void init()
{
    ::init();
    if(!interactive(TP) || avatarp(TP)) return;
    if(!present("monster999")) { new("/d/hm_quest/mon/quest_monster.c")->move(TO); }
    return;
}

int go_back()
{
    if(!present("hm_quest_mon",TO)) return 1;
    tell_object(TP,"You cannot go back while you are fighting!");
    return 0;
}

int GoThroughDoor()
{
    if(!present("hm_quest_mon",TO)) return 1;
    tell_object(TP,"You cannot get by your shadow!");
    return 0;
}
