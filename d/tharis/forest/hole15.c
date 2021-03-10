//hole15.c

#include <std.h>
#include "./forest.h"

inherit ROOM;

void create(){
    ::create();

    set_name("hole");
    set_properties((["indoors":1,"light":0]));
    set_short("A dark hole under the forest");
    set_terrain(BUILT_TUNNEL);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^BLUE%^A dark hole under the forest%^RESET%^
This place is cut roughly from the world. Roots seem to have been torn
out just to feel the tree or plant cringe in pain. Darkness presses against
you. Fetidness clings at your feet.
OLI
    );
    set_smell("default","All the fetid nature of the earth around you reaches your nostrils.");
    set_listen("default","You can hear nothing, as if someone is stopping sound from getting to you.");
    set_exits(([
        "northeast":TFOREST"hole14",
        "southeast":TFOREST"hole16",
        ]));
}
