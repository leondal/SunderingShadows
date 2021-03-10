#include <std.h>
#include "../../ud_ruins.h"

inherit ROOM;

void create(){
    ::create();
    set_name("on the shore of a swift river");
    set_property("indoors",0);
    set_property("light", 0);
    set_property("no teleport", 0);
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_short(
        "%^ORANGE%^on the shore of a %^BOLD%^%^CYAN%^swift river%^RESET%^"
    );
    set_long(
        "%^BOLD%^%^GREEN%^You find yourself upon the bank of a %^CYAN%^swift "
        "river%^GREEN%^. You can see the open sky above you, and there looks "
        "to be signs of civilization through some brush, off in the distance."
        "%^RESET%^"
    );
    set_smell("default", "The air is clean and fresh.");
    set_listen("default", "You hear the steady roar of the river as it flows by.");
    set_exits(([
        "brush" : "/d/darkwood/tabor/road/road5",
    ]));
}
