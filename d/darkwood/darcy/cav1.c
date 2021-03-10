#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 1);
    set_short("A Cavern Below the Chateau");
    set_long(
@DARKWOOD
%^BOLD%^A Cavern Below the Chateau%^RESET%^
  You are in a wide natural gallery under the Chateau d'Arcy. The
air in here is damp, but not as musty as you would think, probably
because there is a little circulation from the outside. You can
still clearly see the entrance to the cave system from here as well
as the entrance to two adjacent caves to the south and the west.

DARKWOOD
);
    set_smell("default","You can smell the stale air.");
    set_exits(([
        "out"   : ROOMDIR+"outside",
        "south" : ROOMDIR+"cav2",
        "west"  : ROOMDIR+"cav0"
    ]));
    set_smell("default","There is a damp and slightly musty scent here.");
    set_listen("default","You hear the sounds of water dripping.");
}

void init(){
    ::init();
        do_random_encounters(({ MONDIR+"merc" }),70,2);
        do_random_encounters(({ MONDIR+"merc" }),30,1);
        do_random_encounters(({ MONDIR+"merc" }),30,1);
}

