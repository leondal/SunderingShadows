#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("2nd Floor");
    set_long("You are standing on the %^ORANGE%^second floor%^WHITE%^,"
			 " which serves as an %^BOLD%^%^CYAN%^observation %^RESET%"
			 "^post and as an entrance to both the %^RED%^roof %^WHITE"
			 "%^and the top of the walls. Atop the %^RED%^roof %^WHITE"
			 "%^stands an impressive %^BOLD%^%^RED%^dwarf made %^RESET"
			 "%^%^ORANGE%^b%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ll%^BO"
			 "LD%^%^BLACK%^i%^RESET%^%^ORANGE%^st%^BOLD%^%^BLACK%^a%^R"
			 "ESET%^, ready to answer any %^BOLD%^%^RED%^threat %^RESE"
			 "T%^from both %^BOLD%^%^GREEN%^land %^RESET%^and %^BOLD%^"
			 "%^CYAN%^sky %^RESET%^with %^BOLD%^%^BLACK%^st%^WHITE%^e%"
			 "^BLACK%^e%^WHITE%^l%^BLACK%^-t%^WHITE%^i%^BLACK%^pp%^WHI"
			 "TE%^e%^BLACK%^d %^RED%^v%^RESET%^%^RED%^i%^BOLD%^o%^RESE"
			 "T%^%^RED%^l%^BOLD%^e%^RESET%^%^RED%^n%^BOLD%^ce%^RESET%^.");
    set_smell("default", "You can smell smoke on the cool, crisp mountain air.");
    set_listen("default","You can overhear several conversations between the g"
						 "uards and the sound of dwarves moving around in metal armor");
						 set_exits(([
	"down" : "/d/dagger/kinaro/guard5"
      ]));
}

