#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(DECAYED_FLOOR);
    set_property("light",2);
    set_property("indoors",0);
	set_short("Drawbridge");
	set_long("
%^BOLD%^Drawbridge%^RESET%^
You carefully step onto the unstable drawbridge. With the eerie moat on "+
"both sides you try to maintain your balance as the wood bends from your "+
"weight. To the north you can see the gates to the castle. "+
"Southward you see a path leading into the marshlands.
	");
    set_exits(([
	"north" : "/d/dagger/marsh/keep/gate.c"
    ] ));
    set_items(([
	"moat" : "You can see something swimming but can't make out what it is.",
	"drawbridge" : "This is an old and battered bridge. Your weight is almost to much for it.",
	"gates" : "You can see the gates to the castle are closed. You wonder if they are locked.",
	"wood" : "The wood that the drawbridge is made from seems to be infested with termites.",
	"castle" : "The castle looks much bigger now that you are closer to it.",
	"path" : "A path leading back into the marshlands."
    ] ));
}
