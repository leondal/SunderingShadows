
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Steps before the greater evil");
        set_long("
    You cross the bridge and immedaitely come to a dark tower with an iron gate.  A staircase begins here and rises to a dark opening above you.
    The magnitude of the evil inside causes the air here to become heavy and it is difficult to breathe.  This is the hall of the Intruder.
    A deathly calm is about you.  The tropical plants and trees are perfectly motionless here.  The mist enshrouds the spindles of the tower giving it an ethereal presence.
");
       set_exits(([
       "west" : "/d/attaya/tower/cbattle",
       "staircase" : "/d/attaya/tower/floor23",
]));
       set_items(([
    "ground" : "You are on a small stone path.  Rich soil lies just off of it from which spring various tropical plants.",
    "plants" : "A wide variety of tropical plants flourishes here.",
    "trees" : "Royal palm trees stand in an orderly row along the path.",
    "walls" : "They have been covered with natural rock or carved.  It is hard to tell that you are still inside!",
    "tower" : "A dismal grey tower of stone and brick stands against the wall here amidst the palm trees.  It is the current home of Intruder.",
    "staircase" : "A staircase of about 72 steps rises to an opening in the tower.",
    "gate" : "It is open...  Intruder has been expecting you.",
    "lighting" : "It is impossible to see the source of the brilliant lighting that fills this chamber.  Mist hangs heavy in the air.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
