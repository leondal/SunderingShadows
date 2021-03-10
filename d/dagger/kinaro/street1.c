#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_short("Street in Kinaro");
    set_long("The %^BOLD%^%^BLACK%^streets %^RESET%^of %^ORANGE%^Kinaro %^WHITE%^are a %^ORANGE%^busy %^WHITE%^place,"
			 " as %^ORANGE%^merchants %^WHITE%^and %^ORANGE%^travellers %^WHITE%^from %^BOLD%^%^CYAN%^Torm %^RESET%^and"
			 " beyond congregate here in the early %^BOLD%^%^GREEN%^spring %^RESET%^after the %^BOLD%^snows %^RESET%^melt,"
			 " and in the %^ORANGE%^f%^RED%^a%^ORANGE%^ll %^WHITE%^after the %^YELLOW%^harvests %^RESET%^to %^ORANGE%^trade goods"
			 " %^WHITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^GREEN%^g%^ORANGE%^e%^RED%^m%^BLUE%^s%^RESET%^."
			 " The %^BOLD%^%^BLACK%^streets %^RESET%^are choked with %^ORANGE%^caravan wagons%^WHITE%^, %^GREEN%^pack mules%^WHITE%^, %^CY"
			 "AN%^travellers %^WHITE%^and busy looking %^ORANGE%^dwarves%^WHITE%^. You are currently on the main street, which runs southeast and northwest.");
    set_smell("default", "%^RESET%^%^ORANGE%^You can smell the ocean nearby mixed with the smell of pack-mules and weary travellers. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between craftmens and merchants,"
	                      " and the faint sound of clinking tankards, and bawdy music in the distance." );
    set_exits(([
	"northwest" : "/d/dagger/kinaro/guard3",
	"southeast" : "/d/dagger/kinaro/street2"
      ]));
}

