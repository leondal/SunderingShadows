//made teleport proof by Circe 11/8/03 to avoid people mis-teleporting to the hm island.  Temporary fix
//teleport proof removed again, is now in the standard shadow pass directory so teleporting won't matter. N, 4/12.
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
//    set_property("no teleport",1);
    set_short("A small office");
    set_long("You have entered a small hut.  There is little furniture to be "
        "seen, and what is here is fairly rustic.  A woman sits alone at a "
        "small table.  She appears to be rather preoccupied with something, "
        "and you notice that she anxiously glances up as you enter the room.");
    set_smell("default","You smell a soothing fragrance in the air.");
    set_listen("default","It is quiet here.");
    set_exits(([
        "east":"/d/shadow/room/pass/pass14"
    ]));
}

void reset() {
    ::reset();
    if(!present("lady")) { new("/d/hm_quest/mon/quest_lady")->move(TO); }
}
