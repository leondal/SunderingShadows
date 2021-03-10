
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Standing before a staircase within the magnificent crystalline tower.");
    set_long("
     You stand within the remarkable crystalline tower of the Kinnesaruda.  The patterns of brilliant light from above sparkle across the floor of polished red marble tiles.  Looking up, the scene is beyond belief.  Hundreds of glistening quartz platfroms float at varying levels and locations throughout the chamber.
    Before you is a magnificent staircase that leads up to a bridge over the reflection pool.  
");
      set_listen("default","You can hear the howl of several large creatures echoing through the immense chamber.");

    set_exits( ([
    "north" : "/d/attaya/base/base39",
    "staircase" : "/d/attaya/base/lookout1",
    "west" : "/d/attaya/base/base46",
     "east" : "/d/attaya/base/base48",
        ]) );
    set_items(([
    "ceiling" : "It is just a faint grey shadow far, far away.",
    "staircase" : "The magnificent staircase is built of gold and walnut tiles arranged like a checkerboard.  The railings are carved marble and decorated by a fine artesin.",
    "platforms" : "The crystal platfroms hang in mid air all over the room.  Some are close to others, some are distant.",
     "water" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
     "walls" : "The walls are made from thousands of glass panels held together by posts of worked steel and bronze.",
      "pool" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
      "floor" : "The floor is comprised completely of polished red marble tiles with gold trim around the edges of each.",
       "up" : "The view above you is breathtaking.",
    ]));

}
void reset(){
   object mon;
   ::reset();

    if(!present("black wyvern")) {
         mon = new("/d/attaya/mon/bwyvern");
	mon->set_id( ({"archer", "guard"}) );
	mon->move(this_object());
   }

}
