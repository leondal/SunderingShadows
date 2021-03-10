#include <std.h>
#include <objects.h>

inherit "std/vault";

void create() {
	::create();
    set_property("light",2);
    set_property("indoors",0);
	set_short("inner ward");
	set_long("
%^BOLD%^Inner ward%^RESET%^
You are careful not to trip over the rusty armor and broken weapons. "+
"The old castle is a desolate place making you feel as if you shouldn't be here. "+
"There is a eary fog that only seems to be within the walls of the castle. "+
"To the east and west you notice the two small towers. Northeast you can see a run down stone building. "+
"To the east and west you notice two small towers. Northeast you can "+
"see futher into the inner ward. To the northwest you notice a small "+
"stone building. Southwards you can see the gates.
	");
	set_exits( ([
	"east" : "/d/dagger/marsh/keep/ward2.c",
	"west" : "/d/dagger/marsh/keep/ward3.c",
	"northeast" : "/d/dagger/marsh/keep/ward4.c",
	"northwest" : "/d/dagger/marsh/keep/ward5.c",
	"south" : "/d/dagger/marsh/keep/gate.c"
	]) );
    set_items(([
	"gates" : "The gates are old and rusty.",
	"castle" : "The castle is in ruins from the weather and lack of care.",
	"towers" : "The towers look as if they haven't been used in years.",
	"fog" : "It's a strange fog that seems to have settled only inside the castle.",
	"armor" : "Rusty armor that is full of hole and dents.",
	"walls" : "The walls of the castle are covered in moss",
	"weapons" : "Broken swords and sheilds litter the ground.",
	"barracks" : "You hope no one sleeps there anymore.",
	"inner ward" : "Broken weapons and armor lie around on the ground.",
	"building" : "The castle buildings are in need of serious repair."
    ] ));

	set_door("gates","/d/dagger/marsh/keep/gate.c","south",0);
	set_string("gates","open","You push open the rusty gates.\n");
}
void reset() {
   ::reset();
	set_open("door",0);
	set_locked("door",0);
	"/d/dagger/marsh/keep/gate.c"->set_open("door",0);
	"/d/dagger/marsh/keep/gate.c"->set_locked("door",0);
}
