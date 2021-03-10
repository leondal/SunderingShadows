#include "./melnmarn.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("East Gates of Shadow.");
    set_long(
@MELNMARN
%^BOLD%^You are at the East Gates of Shadow.%^RESET%^
Before you, you see the tall gates. They loom up high above
your head. There are towers on each side of you. Archways lead
into the towers. The road leads west. There is a branch to the 
southwest. There is a sign near the gate.
MELNMARN
    );
    set_exits( ([
    "southwest":ROOMDIR+"barroad1",
    "west":ROOMDIR+"egroad1",
    "south":ROOMDIR+"eltower",
    "east":"/d/shadow/virtual/desert/25,0.desert",
    "north":ROOMDIR+"enltower"
        ]) );
    set_items(([
      "gate" : "Tall wooden gates. There is no visible way to open them.",
      "archway":"High archways lead into the walls around the city.",
      "sign":"Gates will be opened when the area has been created..:) ",
      "tower":"The towers loom high above the walls.",
      "west":"The road heads west into the city."
               ]));
	set_smell("default","You smell the brisk fragrance of oak, from the gates."); 
	set_listen("default","You hear the sounds of bustling people.");

}
void reset() {
   object mon;

   ::reset();
    if(!present("guard")) {
	mon = new(MONDIR+"guard");
	mon->set_id( ({"guard", "gate guard"}) );
	mon->move(this_object());
   }



    if(!present("guard ")) {
	mon = new(MONDIR+"guard");
	mon->set_id( ({"guard ", "gate guard"}) );
	mon->move(this_object());
    }
}
