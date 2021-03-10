#include <std.h>
#include <objects.h>



inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",3);
   set_property("no teleport",1);
    set_property("indoors",0);
    set_terrain(BARREN);
    set_travel(FOOT_PATH);
    set_short("Rocky pier at Aramanth");
    set_long("
    You stand on the pier of a sinister looking island.  Jagged rock formations rise like twisted limbs beneath a threatening iron grey sky.  A few of the rock formations form spindles far to the east.
You have a good view of the many rock formations on the island from here and notice the abnormally large one to the northeast, near the beach.
    There is a feeling of magic in the air.
    A wooden pier here provides access to boats at sea and provides them a place to dock.
");

     set_listen("default","The waves pound against the dock coating you in a fine mist of seaspray.");
     set_smell("default","The spray off the ocean burns your nose.");
 
    set_exits(([

       "south" : "/d/islands/common/aramanth/room3",
       "east" : "/d/islands/common/aramanth/room4",

    ] ));
    set_items(([
    "pier" : "A series of wooden planks and piers extend into the ocean from here.",
    "dock" : "A series of wooden planks and piers extend into the ocean from here.",
    ] ));
}
void reset(){
   ::reset();
    if(!present("profile"))
      new("/d/islands/common/aramanth/profile")->move(this_object());
}
