#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , -1);
    set_property("indoors" , 1);
    set_short("A Cavern Below the Chateau");
    set_long(
@DARCY
%^BOLD%^A Cavern Below the Chateau%^RESET%^
  You are in a wide cave gallery under the Chateau d'Arcy. The air
in here is damp, and musty due to the complete lack of air
circulation from the outside. This cave connects a small cave to the
north with another cave to the east.

  There appears to be some very tiny fraction of flickering light
coming from the cave to the north.

DARCY
);
    set_exits(([
        "north"  :  ROOMDIR+"cav5",
        "east"   :  ROOMDIR+"cav3"
    ]));
    set_smell("default","There is a damp and musty scent here.");
    set_listen("default","You hear the dripping of water.");
}

void init(){
	::init();
	do_random_encounters(({ MONDIR+"cmerc" }),10,2);
	do_random_encounters(({ MONDIR+"merc" }),80,3);
	do_random_encounters(({ MONDIR+"merc" }),60,2);
	do_random_encounters(({ MONDIR+"merc" }),40,2);
}

