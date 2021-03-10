#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
        set_short("%^ORANGE%^The Fr%^GREEN%^o%^ORANGE%^nt%^GREEN%^i%^ORANGE%^er%^WHITE%^");
    set_long("This %^BOLD%^%^BLACK%^stone building %^RESET%^was once a small %^RED%^barracks%^WHITE%^,"
			 " but has since been bought and converted to a combination of %^ORANGE%^warehouse %^WHITE"
			 "%^and %^CYAN%^store%^WHITE%^. An %^BOLD%^elderly %^RESET%^%^ORANGE%^dwarf %^WHITE%^sits"
			 " behind a well-polished %^ORANGE%^counter %^WHITE%^at the entrance, and invites you to take"
			 " a look around with a sweeping hand %^CYAN%^gesture %^WHITE%^and a broad %^BOLD%^smile%^RESET%^."
			 " Dusty %^ORANGE%^shelves %^WHITE%^stand in rows in the center of the %^CYAN%^shop %^WHITE%^enabling"
			 " you to walk between them and peruse the wares. %^ORANGE%^Crates%^WHITE%^, %^BOLD%^%^BLACK%^boxes %^RESET%"
			 "^and %^ORANGE%^barrels %^WHITE%^are stacked neatly against the walls, %^ORANGE%^dwarf %^BLUE%^runes %^WHI"
			 "TE%^scrawled in %^BOLD%^%^BLACK%^charcoal %^RESET%^designating their contents. Almost every %^BOLD%^%^C"
			 "YAN%^merchant %^RESET%^passing through %^ORANGE%^Kinaro %^WHITE%^stop by here to restock on %^BOLD%^dried"
			 " goods %^RESET%^and %^CYAN%^travelling gear%^WHITE%^. A long %^BOLD%^list %^RESET%^of prices hangs behind the counter."); 
    set_exits((["east" : "/d/dagger/kinaro/street5"]));
	set_smell("default", "The smell of lamp oil, hemp rope and dried meat fills your nostrils. ");
	set_listen("default", "You can hear the muffled sounds of the street outside.");
	set_exits((["east" : "/d/dagger/kinaro/street5"]));
}
void reset(){
    ::reset();
    if(!present("stegg")) {
	new("/d/dagger/kinaro/mon/stegg")->move(TO);
    }
}



