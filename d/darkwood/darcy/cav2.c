#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 1);
    set_short("A Cavern Below the Chateau");
    set_long(
@DARCY
%^BOLD%^A Cavern Below the Chateau%^RESET%^
  You are in a smaller cave under the Chateau d'Arcy. The
air in here is damp, and musty due to the complete lack of air
circulation from the outside. You can see an adjecent cave to your
south and one to your north.

  The passage to the north appears let in some light from the
outside. The passage to the south looks dark and and somewhat
forbidding.

DARCY
);
    set_exits(([
        "north"  :  ROOMDIR+"cav1",
        "south"  :  ROOMDIR+"cav3"
    ]));
    set_smell("default","There is a damp and musty scent here.");
    set_listen("default","You hear the dripping of water.");
}

void init(){
	::init();
	do_random_encounters(({ MONDIR+"merc" }),70,4);
	do_random_encounters(({ MONDIR+"merc" }),20,1);
}

