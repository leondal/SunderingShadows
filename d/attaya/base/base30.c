
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the magnificent crystalline tower.");
    set_long("
     You stand within the remarkable crystalline tower of the Kinnesaruda.  The patterns of brilliant light from above sparkle across the floor of polished red marble tiles.  Looking up, the scene is beyond belief.  Hundreds of glistening quartz platfroms float at varying levels and locations throughout the chamber.
    The size of the chamber itself defies all that you know to be reality.  It is truely phenominal!
");
      set_listen("default","You can hear the howl of several large creatures echoing through the immense chamber.");

    set_exits( ([
    "north" : "/d/attaya/base/base22",
    "south" : "/d/attaya/base/base38",
    "west" : "/d/attaya/base/base29",
     "east" : "/d/attaya/base/base31",
        ]) );
    set_items(([
    "ceiling" : "It is just a faint grey shadow far, far away.",
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

    if(!present("red wyvern")) {
         mon = new("/d/attaya/mon/rwyvern");
	mon->set_id( ({"archer", "guard"}) );
	mon->move(this_object());
   }

}
