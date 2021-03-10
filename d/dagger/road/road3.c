#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    object ob;
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road.");
    set_long("%^CYAN%^You are walking on the road above the "+
	"Dagger Sea coast cliffs. To the southwest you can see the "+
	"town of Muileann in the distance.  To the northeast you can "+
	"see the outpost city of Tonovi and the towns of Torm and Daggerdale.  "+
        "To the east you can see over the great cliffs down to the dagger sea.\n\n"
	"%^RESET%^%^BOLD%^To the north rises an impressive fortress of pure "+
	"white stone. The road to the fortress is well marked by both foot "+
	"traffic and wagons. High walls protect the fortress, but the gate "+
	"stands open.\n%^RESET%^");
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
	"cliffs" : "You can see the ocean below the great granite cliffs",
	"sea" : "The great waves crash against the cliffs hundreds of feet below you.",
      ]));
    set_exits(([
	"northeast" : RPATH "road4",
	"southwest" : RPATH "road2b",
        "north" : "/d/player_houses/yuki/rooms/gate",
      ]));
}
