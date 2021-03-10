#include "/d/dagger/cave2/short.h"

inherit MOBS;

void create() {
    set_floor(2);
    ::create();
    set_long(
      "   You are in a dark damp cavern system descending deep under the mountain.  All around you you see signs of ogre habitation, from fistmarks in the walls to the unmistakable odor.  As you peer into the dark abyss before you you see many glowing eyes peering back at you.  In the middle of the room here there is a large hole in the floor."
    );
    add_item("hole", "The hole here looks like it leads down into another room.  You feel around it and find no handholds.  It looks like the only way down is to jump.");
    set_exits( ([
	"south" : "/d/dagger/cave2/cave44",
      ]));
}

void init() {
    ::init();
    add_action("jump_fcn","jump");
}

int jump_fcn(string str) {
    if(!str) {
	write("jump where?");
	return 1;
    }

    if( (str == "hole") || (str == "into hole") || (str == "in hole") ) {
      tell_object(TP, "%^BLUE%^Ahh, what the hell, why not!\nYou jump into the hole at your feet, and into the darkness!\nAfter falling only a short time, you hit the ground and roll to the side.");
      tell_room(ETP, ""+TPQCN+" sighs as they look into the hole, then suddenly jumps into it.", ({TP}) );
      TP->move_player("/d/dagger/cave2/cave124");
      return 1;
    }
}
