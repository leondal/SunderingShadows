#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
   set("short", "%^YELLOW%^House of Revenue%^RESET%^ ");
    set("long", "This %^BOLD%^plain %^BLACK%^stone building %^RESET%^houses %^ORANGE%^Kinaro's %^BOLD%^tax collectors%^RESET%^."
				" Charged with assessing a %^YELLOW%^one %^BOLD%^percent %^RESET%^fee on all %^ORANGE%^trade goods %^WHITE%^and %^YELLOW%^treasure"
				" %^RESET%^brought into %^YELLOW%^Kinaro%^RESET%^. The %^GREEN%^bookish %^ORANGE%^dwarves %^WHITE%^who work here have the"
				" tenacity of %^RED%^bulldogs %^WHITE%^and the manner of %^BOLD%^prosecuting %^CYAN%^attorneys%^RESET%^. In their eyes, every"
                " %^GREEN%^traveller %^WHITE%^hides %^YELLOW%^taxable %^RESET%^%^GREEN%^goods %^WHITE%^until proven otherwise. They keep care"
				"ful %^BOLD%^records%^RESET%^, and have a reputation for %^BOLD%^%^CYAN%^honesty %^RESET%^despite their %^BOLD%^demeanor%^RESET%^.");
    set_smell("default","%^RESET%^%^ORANGE%^You smell new and old parchment along with coins.");
    set_listen("default","%^RESET%^%^GREEN%^You hear the sounds of clicking of coins.");
	set_exits((["east" : "/d/dagger/kinaro/street2"]));
}
void reset(){
    ::reset();
    if(!present("noranat")) {
	new("/d/dagger/kinaro/mon/noranat")->move(TO);
    }
}



