
#include <std.h>
inherit "/d/attaya/tower/spec/tower";

void create(){
       ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no attack",1);
   set_property("no teleport",1);
       set_short("Floor of the library");
        set_long("%^ORANGE%^Floor of %^ORANGE%^th%^CYAN%^e %^CYAN%^l%^CYAN%^i%^CYAN%^b%^ORANGE%^rar%^CYAN%^y
%^ORANGE%^You are In the southwest corner of the library's ground %^ORANGE%^f%^CYAN%^l%^CYAN%^o%^ORANGE%^or.%^ORANGE%^ A staircase set into the %^CYAN%^w%^ORANGE%^est %^CYAN%^w%^ORANGE%^all%^ORANGE%^ decends into blackness. %^BOLD%^%^ORANGE%^The %^ORANGE%^car%^RESET%^%^ORANGE%^p%^BOLD%^%^ORANGE%^et%^RESET%^%^ORANGE%^ is torn here and a huge gash runs up to the foot of the staircase and away to the east. There is dust on everything and you get the feeling that people don't come down here often.");
       set_exits(([
       "down" : "/d/attaya/tower/link",
       "north" : "/d/attaya/tower/floor3",
       "east" : "/d/attaya/tower/floor2",
]));
       set_items(([
    "ceiling" : "The ceiling is far above you.  A chain sways violently!",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.  A large gash has been ripped in the carpeting as if something sharp were dragged across it.",
    "forms" : "The monsters wander the second level.  The ladder doesn't extend to it, so there must be another way.  You just hope that they aren't rushing down it right now.",
    "bookcases" : "The long bookcases make up wall like rows in the center of the room and again against the outer walls.",
    "books" : "They are too dusty and old to read.  Most have red or brown covers.",
    "walls" : "The walls are comprised of decorated tiles.",
     "gash" : "A gash in the carpet was apparently made when some heavy, sharp object was dragged to the staircase.",
    "tiles" : "The tiles display various patterns and only every so often is one like any other.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
	
    void init(){
      ::init();
  do_random_encounters(({"/d/attaya/mon/supersolstice"}),5,1);
}
