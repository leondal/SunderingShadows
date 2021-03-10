#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger.");
    set_long(
      "%^CYAN%^You are on the north south road leading through dagger. Here you can see a pathway leading to the east, and the Yniam plains to the west."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
	"plains" : "These emerald plains span for a great distance.",
      ]));
    set_exits(([
	"north" : RPATH "road26",
	"south" : RPATH "road24",
        //"east" : "/d/dagger/nurval/room/necro1",
      ]));
}
void reset()
{
    ::reset();
    if(!present("street_light",TO))
        new("/d/common/obj/misc/street_light")->move(TO);
}
