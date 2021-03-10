
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the magnificent crystalline tower.");
    set_long("
    The floor stretches out around you in all directions, as far as you can see in some.  The whole place has the feel of a palace of the gods.  It is too regal, too magestic, too magical to have been built by mortal hands or designed by mortal minds.
    The platforms above you twinkle as the light reflects off of them and you can almost see clouds high above you, inside the enormous glass chamber.
");
      set_listen("default","You can hear the howl of several large creatures echoing through the immense chamber.");

    set_exits( ([
    "north" : "/d/attaya/base/base5",
    "south" : "/d/attaya/base/base21",
    "west" : "/d/attaya/base/base12",
     "east" : "/d/attaya/base/base14",
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

