#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no steal", 1);
    set_short("%^BOLD%^%^BLUE%^Corridor to the Great Hall");
    set_long(
@SEETH
%^BOLD%^%^RED%^A long Corridor leading to the Great Hall%^RESET%^
%^MAGENTA%^You are walking through a dark corridor. The hallway is lit by the eerie glowing of the walls. Toward the end of the corridor, the hallway becomes brighter. To the east, you hear conversations as well as money exchanges.
SEETH
    );
    set_items( ([

      ]) );
    set_exits( ([
        "north" : HALL "ghall.c",
        "south" : HALL "main.c",
        "east" : HALL "bank.c",
      ]) );

    set_smell("default", "You can smell blood and death throughout the hall.");
    set_listen("default", "The Hall is filled with many conversations and deathly sounds.");

}
