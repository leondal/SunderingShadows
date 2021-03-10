#include <std.h>

#include "../../newbie.h"
inherit INH"townmove.c";

void create(){
	::create();
	set_name("archery range");
	set_light(2);
	set_terrain(VILLAGE);
	set_travel(DIRT_ROAD);
	set_short("Archery Range, Offestry");
	set_long(
@NROHT
%^CYAN%^BOLD%^Archery Range, Offestry%^RESET%^
This is the archery range in Offestry.  Archers come here to practice on
the %^CYAN%^targets%^RESET%^ to the north.  There are known to be competitions using the
the farthest target.  Logically, this would be the hardest to hit.  All
around you is trampled grass where the practicing archers have stood for
hours firing at the targets improving their already considerable skills.
At a reasonable range from the first target, you see a line marked in
white chalk.  This is the %^CYAN%^firing line%^RESET%^.  The range master will not allow
you to cross this line, because the result could be an arrow in the
back.

The melee training ground is to the south.

Note: See the trainer to the south if you need to apply proficiencies
for ranged weapons.
NROHT
 	);
	set_items(([
	  "firing line": "This chalk line is the mark to stand on. A properly "+
	  "trained archer will never cross the firing line.",
   	  "targets":"These target are spaced out at farther and farther intervals."+
	  "  Generally, hitting a more distant target will result in better training",
   	]));
	
	set_exits(([
        "north" : "/d/newbie/rooms/special/arch1",
   	"south" : MAINTOWN"trainer",
   	]));
	set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
	if(avatarp(TP)) return 1;
        write("You step back very embarrassed as you hear the other archers "+
          "yell at you for crossing the firing line.");
	return 0;
}
