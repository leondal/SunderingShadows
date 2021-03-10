#include "elf.h"
#include <std.h>

inherit ROOM;

void create() {
        ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
        set_name("archery range");
        set_light(2);
        set_short("The Archery Range");
        set_long("%^GREEN%^This is a training area for"+
		" archers.  Bowmen will come here to test their"+
		" ability with bow and arrow.  Elven archers "+
		"often come here to train.  The area is mostly "+
		"rocks with a few small plants growing here and "+
		"there.   To the north there looks to be %^CYAN%^targets%^GREEN%^"+
		" set up on the cliff for people to hit.  There "+
		"is a %^CYAN%^line%^GREEN%^ also set up so people will not cross "+
		"it and be put in harm's way.");
        set_items(([
                "line" : "This line of rocks is the mark to stand on.  "+
				"Obvious true competitors would never cross it.",
                (({"targets","target"})) :"These target are gradually farther and farther away.  "
				+"Obviously hitting a more distant target will result in better training",
        ]));
        set_exits(([
                "north" : ROOMS"arch0",
                "east"  : ROOMS"stable",
        ]));
        set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
        if(avatarp(TP)) return 1;
        write("You realize that would be really dumb "+
		"as you start to cross the line.");
        return 0;
}
