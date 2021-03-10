#include <std.h>
inherit "/std/church.c";

void create() {
    ::create();
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
    set("short", "%^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^erbobone %^BOLD%^C%^RESET%^%^GREEN%^hurch%^WHITE%^");
    set("long",
"%^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^erbobone %^BOLD%^C%^RESET%^%^GREEN%^hurch%^WHITE%^
%^ORANGE%^You stand inside small wooden church. It is almost empty. Tiny altar with a %^GREEN%^sign %^ORANGE%^above it stands on the far corner. There are no benches and dust on the floor indicates the place seems almost abandoned.%^CYAN%^
"
);
    set_exits( 
	      ([
        "east":"/d/deku/town/road11"
	]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_listen("default", "You hear the faint sounds of "
		      "chants from the back of the church.");
    set_smell("default","You smell the odor of a sweet incense.");
}
