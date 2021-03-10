#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(DEEP_WATER);
   set_travel(FRESH_BLAZE);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("In the lake");
    set_long(
       	"%^BLACK%^%^BLUE%^You dive into the water and are surprised "
	"to discover you can %^CYAN%^breathe%^BLUE%^ here. The water is "
	"murky and dark and you cannot see the bottom of the lake. You do "
	"know which way to surface however.%^RESET%^"
    );
    set_listen("default",
	"You hear the gurgle of water rushing by."
    );
    set_items(([
	"water":"%^BOLD%^%^BLUE%^There is water all around you.%^RESET%^"
    ]));
    set_exits(([
	"surface": RPATH "city22"
    ]));
}
void reset() {
    ::reset();
    if(!present("gar")) {
	new( MPATH "gar1")->move(TO);
        new( MPATH "gar")->move(TO);
        new( MPATH "gar")->move(TO);
        new( MPATH "gar")->move(TO);
    }
}
