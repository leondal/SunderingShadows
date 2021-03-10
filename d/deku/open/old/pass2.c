#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^Shadowlord forest");
    set_long(
@KAYLA
%^BOLD%^%^BLACK%^To the north, through the dark mist rising from the earth, you can see the Fortress.  Dark and gloomy clouds completely obscure the view of its upper levels.  It seems that the Fortress rises to the heavens...... or maybe hell.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","To the west you hear the running water from the river.");
    set_exits(([
       "west" : "/d/deku/open/pass1",
       "north" : "/d/deku/open/pass3"
    ] ));
    set_items(([
    ] ));
}
