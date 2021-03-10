
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Mysterious tropical paradise");
        set_long("
    You step out into a tropical paradise.  It is just like the jungles of Attaya, yet more ordered.  A mist shrouds grand lighting far above you and the walls have been designed to mimic natural rock.
    Rich soil hosts a variety of tropical plants and trees.
Just to the south, you can see a strange black veil.
");
       set_exits(([
       "east" : "/d/attaya/tower/cbattle",
       "south" : "/d/attaya/tower/floor18",
]));
  set_invis_exits( ({"south"}) );
       set_items(([
    "ground" : "You are on a small stone path.  Rich soil lies just off of it from which spring various tropical plants.",
    "plants" : "A wide variety of tropical plants flourishes here.",
    "trees" : "Royal palm trees stand in an orderly row along the path.",
    "walls" : "They have been covered with natural rock or carved.  It is hard to tell that you are still inside!",
    "veil" : "%^BLUE%^A phantom veil of deception hangs here, placed to hide this passage from the other side where the veil mimics a normal wall!",
    "lighting" : "It is impossible to see the source of the brilliant lighting that fills this chamber.  Mist hangs heavy in the air.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
