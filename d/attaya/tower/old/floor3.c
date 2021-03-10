
#include <std.h>
inherit "/d/attaya/tower/spec/tower";

void create(){
       ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no attack",1);
   set_property("no teleport",1);
       set_short("Floor of the library");
        set_long("
    You climb a couple small steps to get to this part of the floor.  It is a slightly raised area that looks out over the library.  A huge globe and a star chart stand here.  A brass railing surrounds them.  There is dust on everything and you get the feeling that people don't come down here often.
    The ceiling is far above you, and shadowy forms slip around the railings of the next level up.  Their glistening silvery eyes peer down upon you and their hatred can be felt in their gaze.
");
       set_exits(([
       "east" : "/d/attaya/tower/floor1a",
       "south" : "/d/attaya/tower/floor4",
]));
       set_items(([
    "ceiling" : "The ceiling is far above you.  A chain sways violently!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "globe" : "It is a magnificent map of the entire world!  You have never seen such a map and cannot pinpoint your location or gauge the world's size but you get the feeling that you have only just begun exploring it.",
    "star chart" : "It is a series of charts plotting the stars and constellations throughout the year.",
    "railing" : "It is a tarnished brass rail running along varnished walnut posts.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.  A large gash has been ripped in the carpeting as if something sharp were dragged across it.",
    "forms" : "The monsters wander the second level.  The ladder doesn't extend to it, so there must be another way.  You just hope that they aren't rushing down it right now.",
    "bookcases" : "The long bookcases make up wall like rows in the center of the room and again against the outer walls.",
    "books" : "They are too dusty and old to read.  Most have red or brown covers.",
    "walls" : "The walls are comprised of decorated tiles.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "gash" : "The gash in the carpet runs west and was apparently made when a sharp heavy object was dragged in that direction.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
	
