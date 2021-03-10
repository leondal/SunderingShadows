#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(3);
    ::create();
    set_long(
      "In this far corner of the caves you have found a strange room.  It looks much the same as the rest, except for a huge crack running up and down the north wall.  From that crack a strange blue light flows, lighting the room."
    );
    set_exits( ([
	"south" : "/d/dagger/cave2/cave117",
      ]));
    add_item("crack", "The crack is large enough for you to walk into, but you wonder what that soft blue light shining from it is.");
    add_item("light", "The soft blue light coming from the crack fills the room, giving it an eerie glow.");
}

void init() {
    ::init();
    add_action("enter_fcn","enter");
}


int enter_fcn(string str) {

    if(str == "crack") {
	write("%^BOLD%^%^BLUE%^   You walk slowly into the glowing crack.\n   As you walk deeper you feel the light all over you as it gets brighter and brighter.  Unable to stop you continue to walk, unable to see through the blinding light.\n   Suddenly there is a great flash and the light disappears, leaving you in a different place.");
	say("%^BOLD%^%^BLUE%^"+TPQCN+" walks into the strange crack, the blue light bathing "+TP->query_objective()+" in its strange light.");
	TP->move("/d/dagger/cave2/cave2");
	TP->force_me("look");
	return 1;
    } else {
      return notify_fail("enter what?\n");
    }
}

void reset(){
    ::reset();

}
