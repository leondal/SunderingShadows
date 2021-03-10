
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
       ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Museum within the Kinnesaruda fortress");
        set_long("
    A great mural covers the northern wall of the museum.  It catches your eye instantly.  Beautiful works of art surround you.  Magnificent gold chandeliers dangle just overhead and water flows from a fountain at the far end of the room filling the room with the soft sounds of rushing water.
    The eyes of the paintings seem to follow you.
");
       set_listen("default", "The sound of rushing water is soothing somehow.");
       set_exits(([
       "south" : "/d/attaya/tower/hall4",
]));
       set_items(([
    "paintings" : "There are four major paintings and a mural on this side of the room.",
    "painting 1" : "%^GREEN%^The shadow of a figure looms over a rugged mountainous landscape.",
    
    "painting 2" : "%^GREEN%^An old lady holds the hand of a young girl who has appearantly passed away in her sleep.  The woman is peering out at you!",
    "painting 3" : "%^GREEN%^A large mountain that stands against the sea.  The profile of the mountain looks like the profile of a man wearing a helmet.",
    "painting 4" : "%^GREEN%^A small wooden shack in a forest of dead trees.  The recent snows are muddied by the hooves of horses.",
    "mural" : "%^CYAN%^From left to right, a great army is advancing on a small town.  In the wake of the army is nothing but blackness.  On the far right is a house that is close enough to see inside.  A young woman sleeps in her bed in the upstairs window and an old lady sits by the fire in the downstairs one.",
    "chandeliers" : "The golden chandeliers are magnificently ornate and each supports thousands of glass prisms.",
    "ceiling" : "The ceiling is vaulted and is held up by greenish arches of copper.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.",
    "floor" : "A blue and gold carpet covers the marble floor.",
    "shadow" : "%^BLUE%^A shadow rests only upon you as if a figure were between you and the light.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/banisher.c"}),55,1);
}
