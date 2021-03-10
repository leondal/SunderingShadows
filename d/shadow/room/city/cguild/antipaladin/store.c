#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
//    set_property("no teleport", 1);
    set_short("%^RED%^Antipaladin Guild Armor Shop%^RESET%^");
set_long("This is the main supply store for the Antipaladins.  They can buy and sell items suitable to their station here to aid them in their service to their god or goddess.   There is a store clerk here ready to serve them.");
    set_exits( ([
	"northeast" : "/d/shadow/room/city/cguild/antipaladin/enter1",
    ]) );
    set_items( ([
    ]));
}

void init() {
    ::init();
    if(!present("keeper"))
	find_object_or_load("/d/shadow/room/city/cguild/mons/antipal_keeper")->move(TO);
}
