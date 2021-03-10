
#include <std.h>
inherit "/d/attaya/tower/spec/tower";

void create(){
       ::create();
      set_travel(RUBBLE);
	set_property("light",2);
	set_property("indoors",1);
   set_property("no attack",1);
   set_property("no teleport",1);
       set_short("Floor of the library");
        set_long("
    You are surrounded by long bookcases filled with dusty books.  Most are too old and worn to read.  A large chandelier has fallen and lies shattered on the floor.  There is dust on everything and you get the feeling that people don't come down here often.
    The ceiling is far above you, and shadowy forms slip around the railings of the next level up.  Their glistening silvery eyes peer down upon you and their hatred can be felt in their gaze.
");
       set_exits(([
       "west" : "/d/attaya/tower/floor3",
       "south" : "/d/attaya/tower/floor2",
]));
       set_items(([
    "ceiling" : "The ceiling is far above you.  A chain sways violently!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "forms" : "The monsters wander the second level.  The ladder doesn't extend to it, so there must be another way.  You just hope that they aren't rushing down it right now.",
    "bookcases" : "The long bookcases make up wall like rows in the center of the room and again against the outer walls.",
    "books" : "They are too dusty and old to read.  Most have red or brown covers.",
    "wreckage" : "Gold and glass are twisted and shattered in a pile on the floor.",
    "chandelier" : "It has fallen and shattered.",
    "chain" : "It sways violently for a bit, no longer weighted down by the chandelier.",
    "walls" : "The walls are comprised of decorated tiles.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
	
