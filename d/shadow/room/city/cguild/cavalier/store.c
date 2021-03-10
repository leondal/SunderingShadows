#include <std.h>
#include "/d/shadow/room/city/cguild/cavalier/cav.h"
inherit ROOM;
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
//    set_property("no teleport", 1);
    set_short("Cavaliers Guild Store");
    set_long(
@DESC
You are in a small store inside the Cavaliers' Guild. There is
a knight standing in front of a storage area, charged with 
helping to equip the cavaliers.
DESC
    );
    set_exits( ([
        "southwest":"/d/shadow/room/city/cguild/cavalier/guild2",
        ]) );
    set_items( ([
        "counter" : "A stone counter used by the knight to display his wares."
    ]));
}
void init(){
    ::init();
    if(!present("knight"))
      find_object_or_load("/d/shadow/room/city/cguild/mons/c_hall_knight")->move(TO);
}
