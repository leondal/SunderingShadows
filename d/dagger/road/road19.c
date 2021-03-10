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
   "%^CYAN%^You are just southwest of the bend in the road through dagger.  To the southwest you can see the road stretch towards Muileann, past Torm.  To the northwest is the Yniam plains, and to the northeast is the town of Daggerdale."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");
    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
	"cliffs" : "You can see the ocean below the great granite cliffs",
	"sea" : "The great waves crash against the cliffs hundreds of feet below you.",
      ]));
    set_exits(([
	"southwest" : RPATH "road18",
	"northeast" : RPATH "road20",
      ]));
}
