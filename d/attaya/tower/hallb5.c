
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("A small room");
        set_long("
    You are inside a small room, if it can be called that.  It is more a crack in the wall than a room.  The wall of the hallway curves from the west to the south.  To the north and east are jagged formations of rock that appear volcanic in nature.
    A few wooden planks and some iron nails have been dumped in here and they lie scattered at your feet.
");
       set_exits(([
       "south" : "/d/attaya/tower/hallb7",
]));
       set_items(([
    "ceiling" : "It is too dark to see clearly.!",
    "floor" : "It is bare granite and volcanic rock.",
    "walls" : "The walls are comprised of decorated tiles.",
    "planks" : "They are like the ones on the ceiling outside...  leftover scrap.",
    "nails" : "Rusty and useless.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
