#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit VAULT;

void create(){
    ::create();
   set_terrain(BARREN);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("no sticks", 1);
    set_property("indoors", 0);
    set_short("Path along the wall");
    set_long(
   "This is a path leading between the Tonovi walls and the Duke's castle.  It ends here at an archway to the north cut into the walls of the Duke's castle wall.  The path is paved with cobblestones and kept very clean by someone."
    );
    set_smell("default", "The air smells stale and of damp stone.");
    set_listen("default", "The sounds of the city are muffled by the walls.");

    set_items( ([
	"walls" : "These sturdy walls ring most of the city, protecting it from invasion.",
        "castle" : "The outer walls of the Duke's castle are even more imposing than those of the city.",
      ]) );
    set_exits( ([
        "archway" : "/d/shadow/room/city/cguild/antipaladin/enter1",
        "southwest" : "/d/dagger/tonovi/antipath1"
      ]) );
   set_door("door","/d/shadow/room/city/cguild/antipaladin/enter1","archway",0);
}
