#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(ROCKY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("The eastern gates of Daggerdale");
    set_short("%^BOLD%^%^BLACK%^The eastern gates of Daggerdale%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These were once the eastern gates of Daggerdale village. The massive %^RESET%^"
"granite walls %^BOLD%^%^BLACK%^surrounding the city are now crumbled, with holes showing and rubble strewn "
"about on the ground. The adamantite chains for the drawbridge are still intact, but the thick wooden bridge "
"itself has been shattered, leaving open access from outside. To the east, the path leads towards a %^RED%^"
"military compound %^BLACK%^with a great hall in the centre.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
	"east" : "/d/dagger/road/p8",
	"west" : STREETS"street25"
    ]));
}