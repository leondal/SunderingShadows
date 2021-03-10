#include <std.h>
#include <arena.h>

inherit ARENAENTER;

void create(){
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_short("%^BOLD%^%^BLUE%^Arena Entrance");
    set_long(
      "You are at the entrance to the arena of the Legion of Lost Souls.  To procede further into the arena, and to combat, type 'enter arena'.  BE WARNED!  This room is NOT of the arena, and deaths here are not mock combat."
    );
    set_smell("default", "There is a smell of wildflowers on a faint breeze.");
    set_listen("default", "You hear combat, and the screams of injury.");
    set_exits( ([
    "southwest" : "/d/guilds/legion/hall/hub.c",
    ]) );
    set_enter_room("/d/guilds/legion/hall/arena/arena12.c");
}
