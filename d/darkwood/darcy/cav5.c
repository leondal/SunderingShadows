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
  You are in a wide cave gallery under the Chateau d'Arcy. The air
in here is damp, and musty due to the complete lack of air
circulation from the outside. You see a lit torch on the wall
towards the southwest corner of the room where this cave connects to
tunnel.  This gallery opens up to a much darker cave to the south.

DARCY
);
    set_exits(([
        "southwest"  :  ROOMDIR+"cav6",
        "south"       :  ROOMDIR+"cav4"
    ]));
    set_smell("default","There is a damp and musty scent here.");
    set_listen("default","You hear the dripping of water.");
}

void init(){
	::init();
	do_random_encounters(({ MONDIR+"merc" }),35,2);
}

