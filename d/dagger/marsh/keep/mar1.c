#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
   set_short("Marshlands");
	set_long("
%^BOLD%^The Marshlands%^RESET%^
You have entered the Marshlands. All around you are the remains of old "+
"rotting trees. The soil is damp and wet with every step. To the north the path "+
"continues on. To the east you notice an overgrown path that is littered with the "+
"old rotting trees.
	");
    set_exits(([
	"east" : "/d/dagger/marsh/keep/mar2.c",
	"north" : "/d/dagger/marsh/keep/mar3.c"
    ] ));
    set_items(([
    ] ));
}
