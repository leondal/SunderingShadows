#include <std.h>

inherit "/d/deku/open/cave_r3i.c";

void create() {
    ::create();
    set_long("This short hallway is very deep into Vexia's lair.  It is "
      "dark and dreary, with the floor and ceilings like the rest, "
      "but something intangible puts you on edge.");       
    set_exits(([
       "west" : "/d/deku/open/vexia",
       "southeast" : "/d/deku/open/guard"
    ] ));
    set_listen("default","An eerie cackle echoes off the walls now and then.");
}

