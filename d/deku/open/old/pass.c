#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_short("The Crossroads");
    set_long(
@KAYLA
%^ORANGE%^Grassy steps and the dark forest give way to grim lands.  At places
the ground is bare, baked, and cracked.  Grass and shrubbery lay dead
in the earth and only a few sickly trees survive by the river to the 
east.  A few steep, craggy hills and dusty canyons open to the north.
%^RED%^There is a large sign here.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/forest10",
       "north" : "/d/deku/open/open",
       "east" : "/d/deku/open/hermit"
    ] ));
    set_items(([
     "sign":"You just entered the hellish and warped realm of Deku'-Arkenazzen. "
             "Death lurks in strange places.  Leaden gray clouds muffle the "
             "sky, sliding lazily across the heavens.  Only fitfully the sun "
             "or moon manages to pierce the cover with golden rays that race "
             "across the ground.  The road forks here.  Off in the distance "
             "toward the northeast lurks the Forbidden Fortress of Shadowlord."
             "  Venture if you dare."
    ] ));
}
