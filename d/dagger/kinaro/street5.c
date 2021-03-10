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
			 " and in the %^ORANGE%^f%^RED%^a%^ORANGE%^ll %^WHITE%^after the %^YELLOW%^harvests %^RESET%^to %^ORANGE%^trade"
			 " goods %^WHITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^GREEN%^g%^ORANGE%^e%^RED%^"
			 "m%^BLUE%^s%^RESET%^. The %^BOLD%^%^BLACK%^streets %^RESET%^are choked with %^ORANGE%^caravan wagons%^WHITE%^,"
			 " %^GREEN%^pack mules%^WHITE%^, %^CYAN%^travellers %^WHITE%^and busy looking %^ORANGE%^dwarves%^WHITE%^. You are"
			 " currently on the main street, which runs north and south. To the west is '%^ORANGE%^The Fr%^GREEN%^o%^ORANGE%^n"
			 "t%^GREEN%^i%^ORANGE%^er%^WHITE%^', and to the east lies %^BOLD%^%^BLACK%^The %^RED%^F%^RESET%^%^RED%^o%^BOLD%^r"
			 "%^RESET%^%^RED%^g%^BOLD%^e%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^of %^CYAN%^Faith%^RESET%^. You see the entrance to"
			 " the %^ORANGE%^mines %^WHITE%^to the southwest, and an %^YELLOW%^e%^CYAN%^xp%^ORANGE%^e%^CYAN%^ns%^ORANGE%^i%^CY"
			 "AN%^v%^ORANGE%^e%^CYAN%^-l%^ORANGE%^o%^CYAN%^oki%^ORANGE%^n%^CYAN%^g %^RESET%^%^ORANGE%^three story %^WHITE%^buil"
			 "ding to the southeast called %^YELLOW%^The %^CYAN%^Tr%^RESET%^%^CYAN%^a%^BOLD%^d%^RESET%^%^CYAN%^e %^YELLOW%^Sp%"
			 "^RESET%^%^ORANGE%^i%^BOLD%^r%^RESET%^%^ORANGE%^e.%^WHITE%^");
    set_smell("default", "You can smell the ocean nearby mixed with the smell of pack-mules and weary travellers.");
    set_listen("default", "You can overhear several conversations between craftmens and merchants and the curious"
						  "combination of chanting and smithing from the east.");
    set_exits(([
		"north" : "/d/dagger/kinaro/street4",
		"west" : "/d/dagger/kinaro/general",
		"east" : "/d/dagger/kinaro/church",
		"southeast" : "/d/dagger/kinaro/spire",
		"southwest" : "/d/dagger/kinaro/mines/mines0",
      ]));
}

