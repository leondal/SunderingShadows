#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_short("Street in Kinaro");
    set_long("The %^BOLD%^%^BLACK%^streets %^RESET%^of %^ORANGE%^Kinaro %^WHITE%^are a %^ORANGE%^busy"
			 " %^WHITE%^place, as %^ORANGE%^merchants %^WHITE%^and %^ORANGE%^travellers %^WHITE%^from %"
			 "^BOLD%^%^CYAN%^Torm %^RESET%^and beyond congregate here in the early %^BOLD%^%^GREEN%^sp"
			 "ring %^RESET%^after the %^BOLD%^snows %^RESET%^melt, and in the %^ORANGE%^f%^RED%^a%^OR"
			 "ANGE%^ll %^WHITE%^after the %^YELLOW%^harvests %^RESET%^to %^ORANGE%^trade goods %^WHIT"
			 "E%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^GREEN%^g%^ORANGE"
			 "%^e%^RED%^m%^BLUE%^s%^RESET%^. The %^BOLD%^%^BLACK%^streets %^RESET%^are choked with %^"
			 "ORANGE%^caravan wagons%^WHITE%^, %^GREEN%^pack mules%^WHITE%^, %^CYAN%^travellers %^WH"
			 "ITE%^and busy looking %^ORANGE%^dwarves%^WHITE%^. You are currently on the main street,"
			 " which runs north and south. To the west is the '%^YELLOW%^House of Revenues%^RESET%^',"
			 " and to the east is %^ORANGE%^The S%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e"
			 " %^RESET%^%^ORANGE%^T%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^v%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^rn%^WHITE%^.");
    set_smell("default", "%^RESET%^%^ORANGE%^You can smell the ocean nearby mixed with the smell of pack-mules and weary travellers.");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between craftmens and merchants, and the faint s"
						  "ound of clinking tankards, and bawdy music from the east");
    set_exits(([
	"northwest" : "/d/dagger/kinaro/street1",
	"south" : "/d/dagger/kinaro/street3",
	"east" : "/d/dagger/kinaro/bar",
	"west" : "/d/dagger/kinaro/revenue"
      ]));
}

