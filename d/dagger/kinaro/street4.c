#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_property("light", 2);
    set_short("Street in Kinaro");
    set_long("The %^BOLD%^%^BLACK%^streets %^RESET%^of %^ORANGE%^Kinaro %^WHITE%^are a %^ORANGE%^busy %^WHITE%^place,"
			 " as %^ORANGE%^merchants %^WHITE%^and %^ORANGE%^travellers %^WHITE%^from %^BOLD%^%^CYAN%^Torm %^RESET%^and"
			 " beyond congregate here in the early %^BOLD%^%^GREEN%^spring %^RESET%^after the %^BOLD%^snows %^RESET%^melt,"
			 " and in the %^ORANGE%^f%^RED%^a%^ORANGE%^ll %^WHITE%^after the %^YELLOW%^harvests %^RESET%^to %^ORANGE%^trade"
			 " goods %^WHITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^GREEN%^g%^ORANGE%^e%^RED%^m%^BLUE%^s%^RESET%^."
			 " The %^BOLD%^%^BLACK%^streets %^RESET%^are choked with %^ORANGE%^caravan wagons%^WHITE%^, %^GREEN%^pack mules%^WHITE%^, %^CYAN%^tr"
			 "avellers %^WHITE%^and busy looking %^ORANGE%^dwarves%^WHITE%^. You are currently on the main street, which runs north and south."
			 "To the west is the %^YELLOW%^L%^RESET%^%^ORANGE%^o%^BOLD%^y%^RESET%^%^ORANGE%^a%^BOLD%^l V%^RESET%^%^ORANGE%^a%^BOLD%^ul%^RESET%^"
			 "%^ORANGE%^t%^BOLD%^s B%^RESET%^%^ORANGE%^a%^BOLD%^nk%^RESET%^, and to the east is the %^ORANGE%^M%^BOLD%^%^BLACK%^i%^RESET%^%^OR"
			 "ANGE%^n%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^rs %^BOLD%^%^RED%^H%^WHITE%^o%^RED%^s%^WHITE%^p%^RED%^i%^WHITE%^t%^RED%^a%^WHITE%^l%^RESET%^.");
    set_smell("default", "%^RESET%^%^ORANGE%^You can smell the ocean nearby mixed with the smell of pack-mules and weary travellers. ");
    set_listen("default", "%^RESET%^%^GREEN%^You can overhear several conversations between craftmens and merchants. ");
    set_exits(([
	"north" : "/d/dagger/kinaro/street3",
	"south" : "/d/dagger/kinaro/street5",
	"east" : "/d/dagger/kinaro/healer",
	"west" : "/d/dagger/kinaro/bank"
      ]));
}

