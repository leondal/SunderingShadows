//hole10.c

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
This dark place lacks the unpleasant atmosphere you expected.
You see dangling roots around you. Whoever dug this hole took care
to do as little harm as they could to the plant life. You feel life
here. The darkness makes you sadly aware of the fact that you are
underground. This room feels guarded. This is obviously where the good
hides it's valuable stuff.

OLI
    );
    set_smell("default","You smell the sweetness of the earth around you.");
    set_listen("default","You can almost hear the earthworms crawl through the earth around you.");
    set_exits(([
        "northeast":TFOREST"hole9",
        "northwest":TFOREST"hole8"
        ]));
}

void reset(){
    ::reset();

    if(!present("white mage"))
        new("/d/tharis/monsters/white_mage")->move(TO);

    if(!present("chest"))
        new("/d/tharis/obj/scroll_chest1")->move(TO);
}

