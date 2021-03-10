
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",1);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Dark passageway");
        set_long("
    You have come to a polished metal doorway.  Just beyond, you can see something on a table shining in the light.  The doorway itself glistens oddly in this dim light as if tiny drops of glowing liquid were slowly dripping down its face.
");
       set_listen("default", "There is an uneasy calm in the stale air.");
       set_exits(([
       "north" : "/d/attaya/tower/hall29",
       "south" : "/d/attaya/tower/hall31",
]));
       set_items(([
    "carpet" : "The dusty carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
     "doorway" : "It is made of a polished metal, perhaps titanium, and stands about seven feet tall.  Three long indentations run down either side and glistening drops of energy move down its face.",
    "indentations" : "The indentations are about a quarter of an inch deep and there are three of them on the face of the doorway on either side.",
    "drops" : "Tiny energy droplets descend from nowhere down the face of the doorway.",
    "droplets" : "Tiny energy droplets descend from nowhere down the face of the doorway.",
    "rubble" : "Parts of the walls, mostly.  Lots of dust.",
    "walls" : "The old plaster walls are in need of refinishing.",
    "ceiling" : "It is too dark to see.",
    "floor" : "A dusty blue and gold carpet covers the marble floor.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
set_pre_exit_functions( ({"south"}), ({"go_south"}) );
	
}
int go_south() {
if(present("field")) {
write("%^BOLD%^%^BLUE%^You slam into the force field!");
return 0;
}
else return 1;
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/obj/forcefield.c"}),100,1);
}
