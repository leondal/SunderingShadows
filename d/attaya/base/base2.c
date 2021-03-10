
#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Inside the magnificent crystalline tower.");
    set_long("
     You are on a small bridge within the unbelievable crystalline tower.  The wall at your back, comprised of hundreds upon thousands of glass panels, stretches upwards out of view.  Within the room of nearly unimaginable proportions are hundreds of transparent platforms no more than a meter thick each that seem to simply float in various spots!
    The sunlight pouring through the numerious crystal and glass structures creates brilliant patterns over everything!
");
      set_listen("default","You can hear the howl of several large creatures echoing through the immense chamber.");

    set_exits( ([
    "south" : "/d/attaya/base/base7",
    "north" : "/d/attaya/base/base1",
        ]) );
    set_items(([
    "ceiling" : "It is just a faint grey shadow far, far away.",
    "platforms" : "The crystal platfroms hang in mid air all over the room.  Some are close to others, some are distant.",
     "water" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
     "walls" : "The walls are made from thousands of glass panels held together by posts of worked steel and bronze.",
      "pool" : "The water in the pool seems to glisten with gold.  You seem to have a bad feeling about it.",
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
