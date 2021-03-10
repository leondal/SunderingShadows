#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("indoors", 1);
//    set_property("no teleport", 1);
    set_property("light", 2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Long dark hallway");
    set_long(
      "You have entered a long dark tunnel like hallway.  Not too far above your head a great archway holds up what seems to almost be the wall of the city.  To the north you can see a bright light filtering in, and to the south you can see the doorway leading to the tack room."
    );
    set_exits( ([
      "north" : "/d/shadow/room/city/cguild/cavalier/guild2",
      "south" : "/d/shadow/room/city/cguild/cavalier/guild1",
    ]) );
    set_listen("default", "You hear the wind whispering through the tunnel.");
//    set_pre_exit_functions( ({"north"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
    if(TP->is_class("cavalier") || TP->is_class("paladin") || TP->is_class("antipaladin") || avatarp(TP)) return 1;
    tell_object(TP, "Until Grendel is done, you may not pass beyond this point.");
    return 0;
}
