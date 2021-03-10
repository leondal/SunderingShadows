#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_short("Street with Guard Tower Access");
    set_property("indoors", 1);

    set_long("The %^BOLD%^%^BLACK%^streets %^RESET%^of %^ORANGE%^Kinaro %^WHITE%^are a"
	         " %^ORANGE%^busy %^WHITE%^place, as %^ORANGE%^merchants %^WHITE%^and %^ORA"
			 "NGE%^travellers %^WHITE%^from %^BOLD%^%^CYAN%^torm %^RESET%^and beyond c"
			 "ongregate here in the early %^BOLD%^%^GREEN%^spring %^RESET%^after the %"
			 "^BOLD%^snows %^RESET%^melt, and in the %^ORANGE%^f%^RED%^a%^ORANGE%^ll %^"
			 "WHITE%^after the %^YELLOW%^harvests %^RESET%^to %^ORANGE%^trade goods %^WH"
			 "ITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^G"
			 "REEN%^g%^ORANGE%^e%^RED%^m%^BLUE%^s%^RESET%^. The %^BOLD%^%^BLACK%^streets"
			 " %^RESET%^are choked with %^ORANGE%^caravan wagons%^WHITE%^, %^GREEN%^pack"
			 "mules%^WHITE%^, %^CYAN%^travellers %^WHITE%^and busy looking %^ORANGE%^dwa"
			 "rves%^WHITE%^. You are currently on the main street, which runs west towar"
			 "ds the gates and east deeper into the %^BOLD%^%^RED%^military outpost%^RESE"
			 "T%^. To the north and south large %^BOLD%^%^BLACK%^defensive towers %^CYAN%^"
			 "loom %^RESET%^25 feet above you.");
    set_smell("default", "%^RESET%^%^ORANGE%^The smell of pack-mules and weary travellers intensifies. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between craftmens and merchants,"
						  "and the faint sound of clinking tankards, and bawdy music in the distance.");

    set_exits(([
	"west" : "/d/dagger/kinaro/guard2",
	"north" : "/d/dagger/kinaro/guard4",
	"south" : "/d/dagger/kinaro/guard5",
	"southeast" : "/d/dagger/kinaro/street1"
      ]));
}

