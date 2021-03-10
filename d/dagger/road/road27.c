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
   "%^CYAN%^You are on the north - south stretch of the dagger road west of Daggerdale, which you can see clearly from here.  To the west you can see the Yniam plains, stretching forever in the distance."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
	"plains" : "These emerald plains span for a great distance.",
      ]));
    set_exits(([
	"north" : RPATH "road28",
	"south" : RPATH "road26",
      ]));
}
