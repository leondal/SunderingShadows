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
  You are in a wide natural gallery under the Chateau d'Arcy. The
air in here is damp, and musty due to the complete lack of air
circulation from the outside. You can see an adjecent cave to your
east and one to your north.

  The passage to the east appears let in some light from the
outside. The passage to the north looks utterly dark and you hear a
strange, hollow sound coming from the chamber.

DARCY
);
    set_exits(([
        "north" : ROOMDIR+"pit",
        "east"  : ROOMDIR+"cav1"
    ]));
    set_smell("default","There is a damp and musty scent here.");
    set_listen("default","You hear a strange hollow sound to the north.");
}

void init(){
	::init();
	do_random_encounters(({ MONDIR+"merc" }),80,2);
	do_random_encounters(({ MONDIR+"merc" }),50,1);
	do_random_encounters(({ MONDIR+"merc" }),40,1);
	do_random_encounters(({ MONDIR+"cmerc" }),10,1);
}

