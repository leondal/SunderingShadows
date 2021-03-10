#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_short("Forbidden Passage");
    set_long(
@KAYLA
This sullen, shadowy place is always covered by gloomy clouds and
inhabited by evil, pale monsters.  Through the dense clouds to the
east there is a large dark tower.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/pass",
       "west" : "/d/deku/plains/plains01",
       "east" : "/d/deku/open/tower"
    ] ));
    set_listen("default","From within the grass are the normal sounds of wildlife.");
    set_items(([
    ] ));
}
