#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Kinaro Main Gates");
    set_long("You stand infront of the %^BOLD%^%^BLACK%^heavily fortified %^WHITE%^gates %^RESET%^of the"
			 " %^ORANGE%^mining %^WHITE%^city of %^ORANGE%^Kinaro%^WHITE%^. Huge blocks of perfectly squa"
			 "red black %^BOLD%^%^BLACK%^granite %^RESET%^forms the city's first line of %^BOLD%^%^CYAN%"
			 "^defence%^RESET%^. The walls are close to 15 feet tall and crested with murder holes. Four"
			 " massive %^ORANGE%^guard towers %^WHITE%^dot the walls with intervals, and the helmets of "
			 " the guards can been seen as they do their rounds. The main road leads right up to the %^B"
			 "OLD%^gate%^RESET%^, which is the only way into the trading outpost. The gate itself is mad"
			 "e of thick, sturdy oak planks reinforced with powerful bands of %^BOLD%^%^BLACK%^steel%^RE"
			 "SET%^. The twin %^BOLD%^gate %^RESET%^can quickly be shut and barred from the inside. Atop"
			 " the %^BOLD%^gate %^RESET%^two gate houses overlook the area and as you look up, you can s"
			 "ee several %^RED%^grim-faced %^ORANGE%^dwarven %^WHITE%^guards armed with %^CYAN%^crossbow"
			 "s %^WHITE%^tracking your movements.");
    set_smell("default", "%^RESET%^%^ORANGE%^You can smell smoke on the cool, crisp mountain air. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between the guards and the sound of dwarves moving around in metal armor.");
    set_exits(([
	"west" : "/d/dagger/kinaro/path3",
	"east" : "/d/dagger/kinaro/guard2"
      ]));
}

void reset() {
    ::reset();
    if(!present("guard")) {
	new("/d/dagger/kinaro/mon/guard1.c")->move(this_object());
	new("/d/dagger/kinaro/mon/tora.c")->move(this_object());
    }
}
