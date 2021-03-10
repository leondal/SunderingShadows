//made teleport proof by Circe 11/8/03 to avoid people mis-teleporting to the hm island.  Temporary fix
#include <std.h>

inherit ROOM;

void create() 
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_property("no teleport",1);
    set_short("A small office");
    set_long("You have entered a small office.  There is little furniture to be "
        "seen.  You see a woman seated behind a large desk.  She appears to "
        "be rather preoccupied with something, and you notice that she "
        "anxiously glances up whenever somebody enters the room.");
    set_smell("default","You smell a soothing fragrance in the air.");
    set_listen("default","You hear the sounds of the city outside.");
    set_exits(([
        "east":"/d/shadow/room/city/eroad9"
    ]));
}

void reset()
{
    ::reset();
    if(!present("lady")) { new("/d/hm_quest/mon/quest_lady")->move(TO); }
}
