#include <std.h>
#include <objects.h>

inherit VAULT;

void create() {
::create();
    set_property("light",2);
    set_property("indoors",0);
	set_short("gates");
	set_long("
%^BOLD%^Gates%^RESET%^
Standing at the gates you can see the inside of the decaying castle. "+
"Battle worn towers and barracks is all you can make out from the view. "+
"The keep is the only building that looks like it could offer any shelter. "+
"To the north you can see the clearing of the inner ward of the castle. "+
"To the south you notice the drawbridge is still holding up.
	");
	set_exits( ([
	"north" : "/d/dagger/marsh/keep/ward1.c",
	"south" : "/d/dagger/marsh/keep/draw.c"
	]) );
    set_items(([
	"gates" : "The gates are old and rusty.",
	"castle" : "The castle is in ruins from the weather and lack of care.",
	"keep" : "The keep looks abondened, or at least you think it is.",
	"drawbridge" : "The drawbridge regains its shape after you stepped off of it.",
	"towers" : "The towers look as if they haven't been used in years.",
	"barracks" : "You hope no one sleeps there anymore.",
	"inner ward" : "Broken weapons and armor lie around on the ground.",
	"building" : "The castle buildings are in need of serious repair."
    ] ));
	set_door("gates","/d/dagger/marsh/keep/ward1.c","north",0);
	set_string("gates","open","You push open the rusty gates.\n");
}
