#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Gate Building");

    set_long("Two %^BOLD%^%^BLACK%^massive %^WHITE%^guard houses %^RESET%^flanked by %^BOLD%^%^BLACK%^steel"
			 "%^RESET%^doors and %^BOLD%^%^BLACK%^reinforced %^RESET%^by a %^BOLD%^%^CYAN%^portcullis%^RESET%^,"
			 " control the ebb and flow of traffic through the %^BOLD%^main gate%^RESET%^. A squad of four"
			 " %^BOLD%^%^RED%^guards %^RESET%^watches the %^BOLD%^gate %^RESET%^at all times. %^BOLD%^%^CYAN%^Merchants"
			 " %^RESET%^and %^ORANGE%^traders %^WHITE%^visiting %^ORANGE%^Kinaro %^WHITE%^are directed to the"
			 " %^YELLOW%^Revenue Hall%^RESET%^, where they must register their goods and pay any appropriate fees"
			 " for conducting business in the town.");
    set_smell("default", "%^RESET%^%^ORANGE%^You can smell smoke on the cool, crisp mountain air.");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between the guards and the sound of dwarves moving around in metal armor");
    set_exits(([
	"east" : "/d/dagger/kinaro/guard3",
	"west" : "/d/dagger/kinaro/guard1"
      ]));
}

void reset() {
    ::reset();
    if(!present("guard")) {
	new("/d/dagger/kinaro/mon/guard1.c")->move(this_object());
	new("/d/dagger/kinaro/mon/guard1.c")->move(this_object());
	new("/d/dagger/kinaro/mon/guard1.c")->move(this_object());
	new("/d/dagger/kinaro/mon/guard1.c")->move(this_object());
    }
}
