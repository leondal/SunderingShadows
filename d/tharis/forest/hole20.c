//hole20.c

#include <std.h>
#include "./forest.h"

inherit ROOM;

void create(){
    ::create();

    set_name("hole");
    set_properties((["indoors":1,"light":0]));
    set_short("A dark hole under the forest");
    set_terrain(BUILT_TUNNEL);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^BLUE%^A dark hole under the forest%^RESET%^
This place is cut roughly from the world. Roots seem to have been torn
out just to feel the tree or plant cringe in pain. Darkness presses against
you. Fetidness clings at your feet. This room feels guarded. This is
obviously where evil stores it's valuables.

OLI
    );
    set_smell("default","You smell the sweetness of the earth around you.");
    set_listen("default","You can almost hear the earthworms crawl through the earth around you.");
    set_exits(([
        "west":TFOREST"hole19",
        ]));
}

void reset(){
    ::reset();

    if(!present("black mage"))
        new("/d/tharis/monsters/black_mage")->move(TO);

    if(!present("chest"))
        new("/d/tharis/obj/scroll_chest2")->move(TO);
}

