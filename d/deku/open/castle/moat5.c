//	moat5.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@MOAT5
You are now at the side of the castle. The moat is much deeper here and you have troubles to keep your head above the water. You see a closed iron gate. When you study it more closely you see that it hasn't got a lock, but that it is built into the walls.
MOAT5
    );
set_smell("default","You smell rotten things from behind the gate. pfffuh !");
set_listen("default","You hear water running.");
    set_exits(([
"south" : CASTLE+"moat4",
"north" : CASTLE+"moat6"
    ] ));
    set_items(([
       "fish" : "You see no fish in the water and not just because it isn't clear anymore !",
       "water" : "The water is dirty and smelly here.",
       "gate" : "The gate is build into the wall and looks very solid."
    ] ));
}
// There are some fish here ... ready to be butchered by low-level players
void reset() {
	::reset();
	if(!(present("rat")))
		new("/d/shadow/mon/rat")->move(this_object());
	     }
