//  Made READABLE By FireDragon
//

#include <std.h>

inherit HEALER;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(3);
    set_property("training",1);
    set_indoors(1);
   set_short("Hersh's House of Healing");
    set_long(
@OLI
You have entered the quiet abode of the Tharis healer. The odors
of various salves and poultices assault your nose as soon as you enter.
Though the shop seems a bit disorganized, it is extraordinarily clean.
Many patients lie on cots, as Hersh quietly tries to tend to them all.
OLI
    );
    set_exits( ([
        "south" : "/d/tharis/Tharis/estreet2"
    ] ));
    set_name("Hersh");
}

void reset(){
    ::reset();
    if(!present("hersh"))
        find_object_or_load("/d/tharis/monsters/hersh")->move(TO);
}
