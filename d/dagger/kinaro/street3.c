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
			 " goods %^WHITE%^for %^BOLD%^%^CYAN%^precious %^BLACK%^metals %^RESET%^and %^BOLD%^%^GREEN%^g%^ORANGE%^e%^RED%"
			 "^m%^BLUE%^s%^RESET%^. The %^BOLD%^%^BLACK%^streets %^RESET%^are choked with %^ORANGE%^caravan wagons%^WHITE%^,"
			 " %^GREEN%^pack mules%^WHITE%^, %^CYAN%^travellers %^WHITE%^and busy looking %^ORANGE%^dwarves%^WHITE%^. You are"
			 " currently on the main street, which runs north and south. To the west is the %^BOLD%^%^CYAN%^G%^RESET%^%^CYAN%^e%^BOLD%^"
			 "%^MAGENTA%^ms%^WHITE%^t%^BLUE%^o%^RESET%^%^MAGENTA%^ne %^BOLD%^%^WHITE%^Smithy%^RESET%^, and to the east is"
			 " %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^ea%^RESET%^%^CYAN%^s%^BOLD%^'s %^WHITE%^S%^RESET%^i%^BOLD%^l%^RES"
			 "ET%^v%^BOLD%^er%^RESET%^e%^BOLD%^d %^RESET%^A%^BOLD%^x%^RESET%^e.");
    set_smell("default", "You can smell the ocean nearby mixed with the smell of pack-mules and weary travellers.");
    set_listen("default", "You can overhear several conversations between craftmens and merchants and the sound of hammer on metal from the west.");
    set_exits(([
	"north" : "/d/dagger/kinaro/street2",
	"south" : "/d/dagger/kinaro/street4",
	"east" : "/d/dagger/kinaro/weap",
	"west" : "/d/dagger/kinaro/armor"
      ]));
}

